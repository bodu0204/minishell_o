/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_excution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "execunit.h"
#include "execution.h"
#include "ft_string.h"
#include "ft_utils.h"
#include "error.h"
#include "cache.h"

//tmp
void	exec_init_argv(t_exec *ctx, t_proc *proc)
{
	char			**now;
	t_cmds			*cmds;

	proc->argc = ft_clst_size(proc->cmds);
	proc->argv = or_exit(malloc(sizeof(char *) * (proc->argc + 1)), ctx);
	now = proc->argv;
	cmds = ft_clstfirst(proc->cmds);
	while (!ft_clst_isend(cmds))
	{
		*now++ = or_exit(ft_strdup(cmds->data), ctx);
		cmds = cmds->next;
	}
	*now = NULL;
}

bool	exec_set_builtin(t_proc *proc, bool is_single)
{
	t_executor	builtin_func;

	builtin_func = exec_find_builtin_func(*proc->cmd);
	if (!builtin_func)
		return (false);
	proc->executor = builtin_func;
	if (is_single)
		proc->launcher = exec_parent;
	else
		proc->launcher = exec_child;
	return (true);
}

bool	exec_set_external(t_exec *ctx, t_proc *proc)
{
	char	*cmdpath;

	proc->launcher = exec_child;
	proc->executor = exec_external_cmd;
	if (cache_exists(*proc->cmd))
		cmdpath = or_exit(ft_strdup(cache_get(*proc->cmd)), ctx);
	else
		cmdpath = exec_create_cmdpath(ctx, proc, *proc->cmd);
	proc->cmdpath = cmdpath;
	return (cmdpath != NULL);
}
