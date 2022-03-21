/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "lexer.h"
#include "ft_string.h"
#include "ft_list.h"
#include "ft_io.h"
#include "token.h"
#include "error.h"
#include "del.h"

void	lex_remove_sp_token(t_lex *lex)
{
	t_tokens	*now;
	t_tokens	*next;
	t_token		*token;

	now = lex->tokens->next;
	while (!ft_clst_isend(now))
	{
		next = now->next;
		token = now->data;
		if (token->type == T_SP)
			ft_clst_popdel(now, free);
		now = next;
	}
}

void	lex_correct_digits_token(t_lex *lex)
{
	t_token		*token;
	t_tokens	*tokens;

	tokens = lex->tokens->next;
	while (!ft_clst_isend(tokens))
	{
		token = tokens->data;
		if (token->type == T_DIGITS && token->len > 1)
			token->type = T_STR;
		tokens = tokens->next;
	}
}

void	lex_assign_fd_token(t_lex *lex)
{
	t_token		*now;
	t_token		*next;
	t_tokens	*tokens;

	tokens = lex->tokens->next;
	while (!ft_clst_isend(tokens))
	{
		now = tokens->data;
		next = tokens->next->data;
		if (lex_is_fd(now, next))
			now->type = T_FD;
		tokens = tokens->next;
	}
}

bool	lex_tokenize(t_lex *lex)
{
	lex->tokens = or_exit(ft_clstnew(NULL), lex);
	while (lex->input[lex->idx])
	{
		if (!lex_isspecial(lex->input[lex->idx]))
		{
			if (!lex_tokenize_literal(lex))
			{
				ft_clst_clear(&lex->tokens, free);
				msh_puterr(ERR_LEX_MISS_QUOTE);
				return (false);
			}
		}
		else if (lex_isop(lex->input[lex->idx]))
			lex_tokenize_op(lex);
		else if (lex_isspace(lex->input[lex->idx]))
			lex_tokenize_sp(lex);
	}
	return (true);
}

bool	lexer(char *input, t_tokens **out_tokens)
{
	t_lex	lex;

	*out_tokens = NULL;
	lex = (t_lex){.del.func = lex_del, .input = input};
	if (!lex_tokenize(&lex))
		return (false);
	lex_correct_digits_token(&lex);
	lex_assign_fd_token(&lex);
	lex_remove_sp_token(&lex);
	lex_add_newtok(T_NEWLINE, "newline", 7, &lex);
	*out_tokens = lex.tokens;
	return (true);
}
