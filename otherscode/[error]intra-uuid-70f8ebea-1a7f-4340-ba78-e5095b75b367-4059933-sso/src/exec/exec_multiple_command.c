/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

#include <stdio.h>
#include <sys/wait.h>
#include "libft.h"
#include "cmd.h"
#include "define.h"
#include "utils.h"

#include "signal_handler.h"

//TODO error checks(fork, etc)
void	set_pipe(t_cmd *cmd, t_cmd *prev_cmd, bool is_first, bool is_last)
{
	int		pipe_read_fd;
	int		pipe_write_fd;

	if (is_first)
		cmd->infd = STDIN_FILENO;
	else
		cmd->infd = prev_cmd->to_next_infd;
	if (is_last)
	{
		cmd->outfd = STDOUT_FILENO;
		return ;
	}
	else
	{
		wrap_pipe(&pipe_read_fd, &pipe_write_fd);
		cmd->outfd = pipe_write_fd;
		cmd->to_next_infd = pipe_read_fd;
		return ;
	}
}

int	child_proc(t_cmd *cmd, bool is_last)
{
	int	exec_ret;

	restore_signal_handler();
	if (!is_last)
		close(cmd->to_next_infd);
	if (cmd->heredoc_str)
		close(cmd->heredoc_write_fd);
	dup_fd(cmd);
	if (set_redirect(cmd) == false)
		exit(1);
	exec_ret = exec_command(cmd->argv);
	exit(exec_ret);
}

static int	run_all_cmd(t_dlst *cmd_dlst)
{
	t_cmd	*cmd;

	cmd_dlst = cmd_dlst->next;
	while (cmd_dlst->content)
	{
		cmd = cmd_dlst->content;
		set_pipe(cmd_dlst->content, cmd_dlst->prev->content, \
			!cmd_dlst->prev->content, !cmd_dlst->next->content);
		if (cmd->heredoc_str)
			set_heredoc_fd(cmd);
		cmd->pid = wrap_fork();
		if (cmd->pid == 0)
		{
			child_proc(cmd, !cmd_dlst->next->content);
			exit(1);
		}
		else
		{
			close_fd(cmd);
		}
		cmd_dlst = cmd_dlst->next;
	}
	return (0);
}

static void	wait_process(void *ptr)
{
	int		ret;
	t_cmd	*cmd;

	cmd = ptr;
	waitpid(cmd->pid, &ret, 0);
	if (WIFEXITED(ret))
	{
		cmd->exit_status = WEXITSTATUS(ret);
		return ;
	}
	if (WIFSIGNALED(ret))
	{
		cmd->sig = WTERMSIG(ret);
		cmd->exit_status = cmd->sig + 128;
		return ;
	}
	return ;
}

int	exec_multiple_command(t_dlst *cmd_dlst)
{
	int	ret;

	run_all_cmd(cmd_dlst);
	ft_dlstiter(cmd_dlst, &write_heredoc);
	ft_dlstiter(cmd_dlst, &wait_process);
	ret = get_last_cmd_exit_status(cmd_dlst);
	return (ret);
}
