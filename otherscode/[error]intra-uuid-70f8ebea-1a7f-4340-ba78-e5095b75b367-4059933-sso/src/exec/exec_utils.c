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
#include "cmd.h"

void	dup_fd(t_cmd *cmd)
{
	if (cmd->infd != STDIN_FILENO)
	{
		if (dup2(cmd->infd, STDIN_FILENO) == -1)
		{
			return ;
		}
		close(cmd->infd);
	}
	if (cmd->outfd != STDOUT_FILENO)
	{
		if (dup2(cmd->outfd, STDOUT_FILENO) == -1)
		{
			return ;
		}
		close(cmd->outfd);
	}
}

void	close_fd(t_cmd *cmd)
{
	if (cmd->outfd != STDOUT_FILENO)
		close(cmd->outfd);
	if (cmd->infd != STDIN_FILENO)
		close(cmd->infd);
}
