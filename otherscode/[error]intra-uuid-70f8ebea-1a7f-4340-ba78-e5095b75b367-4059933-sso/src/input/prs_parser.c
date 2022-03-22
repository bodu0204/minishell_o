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

#include "input.h"

#include <stdio.h>

#include "token.h"
#include "cmd.h"
#include "libft.h"
#include "utils.h"

#include "error.h"

bool	pipe_case(t_dlst *pipe_token, t_dlst *next)
{
	remove_tkn_node(pipe_token);
	if (next->content == NULL)
		return (false);
	return (true);
}

// TODO
bool	reconnect_to_red_dlst(t_cmd *cmd, t_dlst *token, t_dlst *file)
{
	t_red	*new_red;
	t_dlst	*to_append_node;

	if (file->content == NULL)
		return (false);
	new_red = construct_red(token->content, file->content);
	token->content = NULL;
	file->content = NULL;
	remove_tkn_node(token);
	remove_tkn_node(file);
	to_append_node = ft_dlstnew(new_red);
	if (!to_append_node)
		put_strerror_and_exit();
	ft_dlstadd_back(&cmd->redirect_info_dlst, to_append_node);
	return (true);
}

void	reconnect_to_arg_dlst(t_cmd *cmd, t_dlst *token)
{
	token = ft_dlst_eject(token);
	ft_dlstadd_back(&cmd->arg_token_dlst, token);
}

bool	parse_token_dlst(t_dlst *token_dlst, t_dlst *cmd_dlst)
{
	t_cmd	*cmd;
	t_dlst	*token_node;

	cmd = construct_cmd(cmd_dlst);
	while (!ft_dlst_is_empty(token_dlst))
	{
		token_node = token_dlst->next;
		if (is_pipe(token_node->content))
		{
			cmd = construct_cmd(cmd_dlst);
			if (!cmd || !pipe_case(token_node, token_node->next))
				return (false);
		}
		else if (is_redirect(token_node->content))
		{
			if (!reconnect_to_red_dlst(cmd, token_node, token_node->next))
				return (false);
		}
		else
		{
			reconnect_to_arg_dlst(cmd, token_node);
		}
	}
	return (true);
}

bool	parser(t_dlst *token_dlst, t_dlst *cmd_dlst)
{
	if (!is_valid_syntax(token_dlst))
		return (false);
	if (!parse_token_dlst(token_dlst, cmd_dlst))
		return (false);
	if (!load_heredoc(cmd_dlst))
		return (false);
	return (true);
}
