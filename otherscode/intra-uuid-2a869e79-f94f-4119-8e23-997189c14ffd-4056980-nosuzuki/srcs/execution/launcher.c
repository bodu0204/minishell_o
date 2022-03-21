/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include "execution.h"
#include "execunit.h"
#include "stdfd.h"
#include "wrapper.h"
#include "variable.h"

int	exec_external_cmd(t_exec *ctx, size_t argc, char **argv, char *cmdpath)
{
	(void)argc;
	if (ft_execve(cmdpath, argv, ctx->env) == SYS_ERR)
		return (ST_ERR_PERMIT);
	return (0);
}

bool	exec_parent(t_exec *ctx, t_proc *proc)
{
	proc->builtin_status = proc->executor(ctx, proc->argc, proc->argv);
	return (true);
}

//tmp
bool	exec_child(t_exec *ctx, t_proc *proc)
{
	pid_t	pid;
	int		status;

	pid = ft_fork();
	if (pid == SYS_ERR)
	{
		proc->error_status = ST_ERR_FORK;
		return (false);
	}
	else if (pid == 0)
	{
		var_set_child(ctx);
		ft_close(FD_NEXT_PIPE_IN);
		status = proc->executor(ctx, proc->argc, proc->argv, proc->cmdpath);
		exit(status);
	}
	else
	{
		proc->pid = pid;
		return (true);
	}
}
