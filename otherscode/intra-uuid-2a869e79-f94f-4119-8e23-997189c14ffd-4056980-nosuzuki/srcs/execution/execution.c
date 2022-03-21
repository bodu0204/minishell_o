/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "execution.h"
#include "minishell.h"
#include "variable.h"
#include "expansion.h"
#include "execunit.h"
#include "error.h"
#include "ft_list.h"
#include "ft_free.h"
#include "signals.h"
#include "ft_io.h"
#include "del.h"
#include "wrapper.h"

/*
	access -> break条件
*/

extern t_msh	g_;

void	exec_store_exit_status(t_exec *ctx, t_proc *proc)
{
	int		exit_status;

	if (proc->error_status == ST_SUCCESS)
	{
		if (proc->pid)
			exit_status = proc->wait_status;
		else
			exit_status = proc->builtin_status;
	}
	else
		exit_status = proc->error_status;
	var_update_exit_status(ctx, exit_status);
}

bool	exec_proc(t_exec *ctx, t_proc *proc, bool is_single)
{
	proc->error_status = ST_SUCCESS;
	if (expansion(ctx, proc) && exec_redir(proc))
	{
		exec_init_argv(ctx, proc);
		if (exec_set_builtin(proc, is_single) || exec_set_external(ctx, proc))
			return (proc->launcher(ctx, proc));
		else
			return (true);
	}
	else
		return (true);
}

t_proc	*exec_all_procs(t_exec *ctx, t_procs *procs)
{
	bool		is_single;
	bool		is_continue;
	t_proc		*latest_proc;

	exec_backup_stdfd();
	is_continue = true;
	is_single = ft_clst_size(procs) == 1;
	procs = ft_clstfirst(procs);
	while (!ft_clst_isend(procs) && is_continue)
	{
		latest_proc = procs->data;
		exec_setup_pipe_connection(procs);
		is_continue = exec_proc(ctx, procs->data, is_single);
		exec_restore_stdfd();
		procs = procs->next;
	}
	ft_close(FD_NEXT_PIPE_IN);
	return (latest_proc);
}

void	exec_all(t_exec *ctx, t_procs *procs)
{
	t_proc	*last_proc;

	ctx->env = var_get_all_str(ctx, g_.env);
	last_proc = exec_all_procs(ctx, procs);
	if (exec_has_child(procs))
		exec_waitpid_all(last_proc);
	exec_store_exit_status(ctx, last_proc);
	ft_free_strs(&ctx->env);
}

//tmp
bool	execution(t_procs *execs)
{
	t_exec	ctx;

	if (ft_clst_isempty(execs))
		return (true);
	g_.signum = 0;
	ctx = (t_exec){.del.func = exec_del, .execunits = execs};
	exec_all(&ctx, execs);
	if (g_.signum)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (true);
}
