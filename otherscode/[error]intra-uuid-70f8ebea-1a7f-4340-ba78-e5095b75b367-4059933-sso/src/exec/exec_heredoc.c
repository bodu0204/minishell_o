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
#include "cmd.h"
#include "utils.h"

// TODO : close heredoc write pd ?
void	set_heredoc_fd(t_cmd *cmd)
{
	int	pipe_in;
	int	pipe_out;

	wrap_pipe(&pipe_in, &pipe_out);
	if (cmd->infd != STDIN_FILENO)
		close(cmd->infd);
	cmd->infd = pipe_in;
	cmd->heredoc_write_fd = pipe_out;
	return ;
}

void	write_heredoc(void *ptr)
{
	t_cmd	*cmd;

	cmd = ptr;
	if (!cmd->heredoc_str)
		return ;
	ft_putstr_fd(cmd->heredoc_str, cmd->heredoc_write_fd);
	close(cmd->heredoc_write_fd);
	return ;
}
