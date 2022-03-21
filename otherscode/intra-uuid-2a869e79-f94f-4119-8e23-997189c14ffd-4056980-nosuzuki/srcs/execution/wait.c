/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "execution.h"
#include "ft_io.h"
#include "wrapper.h"
#include "signals.h"

pid_t	exec_has_child(t_procs *procs)
{
	t_proc	*proc;

	procs = ft_clstfirst(procs);
	while (!ft_clst_isend(procs))
	{
		proc = procs->data;
		if (proc->pid)
			return (true);
		procs = procs->next;
	}
	return (false);
}

int	exec_get_shell_exit_status(int raw_status)
{
	if (WIFEXITED(raw_status))
		return (WEXITSTATUS(raw_status));
	else if (WIFSIGNALED(raw_status))
	{
		if (WCOREDUMP(raw_status))
			ft_putendl_fd(ERR_SEGV, 2);
		return (WTERMSIG(raw_status) + SIG_EXIT_OFFSET);
	}
	else if (WIFSTOPPED(raw_status))
		return (WSTOPSIG(raw_status) + SIG_EXIT_OFFSET);
	else if (WIFCONTINUED(raw_status))
		return (SIGCONT + SIG_EXIT_OFFSET);
	return (0);
}

void	exec_waitpid_all(t_proc *proc)
{
	int		status;
	pid_t	pid;

	while (true)
	{
		pid = ft_waitpid(-1, &status, 0);
		if (pid == -1 && errno == EINTR)
			continue ;
		else if (pid == -1 && errno == ECHILD)
			break ;
		if (pid != 0 && pid == proc->pid)
			proc->wait_status = exec_get_shell_exit_status(status);
	}
}
