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
#include "libft.h"
#include "shell_info.h"
#include "cmd.h"
#include "utils.h"
#include "define.h"

int	exec_only_builtin(t_cmd *cmd)
{
	int	exec_ret;
	int	backup_in;
	int	backup_out;
	int	set_red_ret;

	backup_in = dup(STDIN_FILENO);
	backup_out = dup(STDOUT_FILENO);
	set_red_ret = set_redirect(cmd);
	if (set_red_ret != false)
		exec_ret = exec_builtin(cmd->argv);
	dup2(backup_in, STDIN_FILENO);
	dup2(backup_out, STDOUT_FILENO);
	close(backup_in);
	close(backup_out);
	if (set_red_ret == false)
		return (1);
	return (exec_ret);
}

void	set_cmd_exit_status(int ret)
{
	if (get_sig())
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		set_exit_status(get_sig() + 128);
		reset_sig();
	}
	else
		set_exit_status(ret);
}

void	put_quit_msg(int sig)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	ft_putstr_fd("received signal: ", STDERR_FILENO);
	ft_putnbr_fd(sig, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	execution(t_dlst *cmd_dlst)
{
	int		cmd_count;
	int		ret;
	t_cmd	*cmd;

	reset_sig();
	cmd_count = ft_dlstsize(cmd_dlst);
	cmd = cmd_dlst->next->content;
	if (is_builtin(*(cmd->argv)) && cmd_count == 1)
	{
		ret = exec_only_builtin(cmd);
	}
	else
	{
		ret = exec_multiple_command(cmd_dlst);
		if (get_last_cmd_sig(cmd_dlst))
			put_quit_msg(get_last_cmd_sig(cmd_dlst));
	}
	set_cmd_exit_status(ret);
}
