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

#include <stdio.h>

#include "cmd.h"
#include "token.h"
#include "utils.h"
#include "libft.h"
#include "error.h"

t_cmd	*construct_cmd(t_dlst *cmd_dlst)
{
	t_cmd	*cmd;
	t_dlst	*node;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		put_strerror_and_exit();
	cmd->arg_token_dlst = ft_dlstinit();
	if (!cmd->arg_token_dlst)
		put_strerror_and_exit();
	cmd->redirect_info_dlst = ft_dlstinit();
	if (!cmd->redirect_info_dlst)
		put_strerror_and_exit();
	node = ft_dlstnew(cmd);
	if (!node)
		put_strerror_and_exit();
	ft_dlstadd_back(&cmd_dlst, node);
	return (cmd);
}

// TODO : ft_dlstclear
void	destruct_cmd(void *ptr)
{
	t_cmd	*cmd;

	if (ptr == NULL)
		return ;
	cmd = ptr;
	if (cmd->argv != NULL)
		ft_free_dptr((void ***)&cmd->argv);
	if (cmd->heredoc_str)
		ft_free_ptr((void **)&cmd->heredoc_str);
	if (cmd->arg_token_dlst != NULL)
		ft_dlstclear(&cmd->arg_token_dlst, &free);
	if (cmd->redirect_info_dlst != NULL)
		destruct_red_dlst(&cmd->redirect_info_dlst);
	ft_free_ptr((void **)&cmd);
}

bool	construct_cmd_dlst(t_dlst **cmd_dlst)
{
	*cmd_dlst = ft_dlstinit();
	if (!*cmd_dlst)
		return (false);
	return (true);
}

void	destruct_cmd_dlst(t_dlst **cmd_dlst)
{
	ft_dlstclear(cmd_dlst, &destruct_cmd);
}
