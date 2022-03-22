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

#include "cmd.h"

#include <stdio.h>
#include "libft.h"
#include "error.h"

int	get_cmd_exit_status(t_cmd *cmd)
{
	if (!cmd)
		return (-1);
	return (cmd->exit_status);
}

int	get_last_cmd_exit_status(t_dlst *cmd_dlst)
{
	return (get_cmd_exit_status(cmd_dlst->prev->content));
}

int	get_last_cmd_sig(t_dlst *cmd_dlst)
{
	t_cmd	*last_cmd;

	last_cmd = cmd_dlst->prev->content;
	if (!last_cmd)
		return (-1);
	return (last_cmd->sig);
}

void	conv_arg(t_dlst *cmd_dlst)
{
	t_cmd	*cmd;

	if (cmd_dlst == NULL)
		return ;
	cmd_dlst = cmd_dlst->next;
	while (cmd_dlst->content != NULL)
	{
		cmd = cmd_dlst->content;
		cmd->argv = (char **)ft_dlst_to_dptr(&cmd->arg_token_dlst);
		if (!cmd->argv)
			put_strerror_and_exit();
		cmd_dlst = cmd_dlst->next;
	}
}
