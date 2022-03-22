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
#include <stdbool.h>
#include "libft.h"
#include "utils.h"
#include "error.h"

static bool	is_pipe_syntax_correct(t_dlst *pipe_node, bool has_command)
{
	if (pipe_node->next->content == NULL)
	{
		put_err_msg("minish: syntax error: unexpected end of file");
		return (false);
	}
	if (!has_command)
	{
		put_err_msg("minish: syntax error near unexpected token `||'");
		return (false);
	}
	return (true);
}

static bool	is_redirect_syntax_correct(t_dlst *redirect_node)
{
	char	*redirect_target;

	redirect_target = redirect_node->next->content;
	if (redirect_target == NULL)
	{
		put_err_msg("minish: redirect target is not exists.");
		return (false);
	}
	if (is_meta_str(redirect_target))
	{
		put_err_msg("minish: metacharacter unavailable redirect target.");
		return (false);
	}
	return (true);
}

// Is even one command present?
// is_valid_parse
// is_valid_syntax
bool	is_valid_syntax(t_dlst *token_dlst)
{
	char	*iter_s;
	bool	has_command;

	token_dlst = token_dlst->next;
	has_command = false;
	while (token_dlst->content)
	{
		iter_s = token_dlst->content;
		if (is_pipe(iter_s))
		{
			if (!is_pipe_syntax_correct(token_dlst, has_command))
				return (false);
			has_command = false;
		}
		else if (is_redirect(iter_s))
		{
			if (!is_redirect_syntax_correct(token_dlst))
				return (false);
		}
		else
			has_command = true;
		token_dlst = token_dlst->next;
	}
	return (true);
}
