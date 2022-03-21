/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "ft_string.h"
#include "ft_ctype.h"
#include <stdlib.h>

void	lex_add_newtok(t_ttype type, const char *start, size_t len, t_lex *lex)
{
	t_token		*token;
	t_tokens	*new;

	new = or_exit(ft_clstnew_add_back(lex->tokens, NULL), lex);
	token = or_exit(malloc(sizeof(t_token)), lex);
	token->type = type;
	token->start = start;
	token->len = len;
	lex->idx += len;
	new->data = token;
}

bool	lex_tokenize_sp(t_lex *lex)
{
	const char	*start = lex->input + lex->idx;
	size_t		len;

	len = 0;
	while (lex_isspace(start[len]))
		len++;
	if (len == 0)
		return (false);
	lex_add_newtok(T_SP, start, len, lex);
	return (true);
}

bool	lex_tokenize_op(t_lex *lex)
{
	const char	*start = lex->input + lex->idx;

	if (!ft_strncmp(start, "<<", 2))
		lex_add_newtok(T_HDOC, start, 2, lex);
	else if (!ft_strncmp(start, ">>", 2))
		lex_add_newtok(T_REDIR_APP, start, 2, lex);
	else if (!ft_strncmp(start, "<", 1))
		lex_add_newtok(T_REDIR_IN, start, 1, lex);
	else if (!ft_strncmp(start, ">", 1))
		lex_add_newtok(T_REDIR_OUT, start, 1, lex);
	else if (!ft_strncmp(start, "|", 1))
		lex_add_newtok(T_PIPE, start, 1, lex);
	else
		return (false);
	return (true);
}

bool	lex_tokenize_literal(t_lex *lex)
{
	const char	*start = lex->input + lex->idx;
	size_t		len;
	t_ttype		type;
	char		*next_quote;

	len = 0;
	type = T_STR | T_NUM_BIT;
	while (start[len] && !lex_isspecial(start[len]))
	{
		if (lex_isquote(start[len]))
		{
			type = T_STR;
			next_quote = ft_strchr(start + len + 1, start[len]);
			if (!next_quote)
				return (false);
			len = next_quote - start;
		}
		else if (!ft_isdigit(start[len]))
			type = T_STR;
		len++;
	}
	lex_add_newtok(type, start, len, lex);
	return (true);
}
