/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion.h"
#include "ft_list.h"
#include "ft_string.h"
#include "execution.h"
#include "execunit.h"
#include "error.h"
#include "lexer.h"
#include "del.h"

t_etok	*exp_create_token(void *ctx, t_etype ty, size_t len, char *start)
{
	t_etok	*token;

	token = or_exit(malloc(sizeof(t_etok)), ctx);
	token->del.func = etok_del;
	token->type = ty;
	token->str = ft_substr(start, 0, len);
	if (!token->str)
	{
		free(token);
		or_exit(NULL, ctx);
	}
	return (token);
}

t_etok	*exp_create_quote_token(void *ctx, char **str, t_etype type)
{
	char	quote;
	char	*next_quote;
	char	*start;
	size_t	len;

	start = *str;
	quote = *start;
	next_quote = ft_strchr(start + 1, quote);
	len = next_quote - start - 1;
	*str = next_quote + 1;
	return (exp_create_token(ctx, type, len, start + 1));
}

t_etok	*exp_create_unquote_token(void *ctx, char **str)
{
	char	*start;
	char	*end;
	size_t	len;

	start = *str;
	end = start;
	while (*end && !lex_isquote(*end))
		end++;
	len = end - start;
	*str = end;
	return (exp_create_token(ctx, E_UNQUOTE, len, start));
}

void	exp_tokenize_quote(void *ctx, char *str, t_clist *tokens)
{
	t_clist		*now;

	while (*str)
	{
		now = or_exit(ft_clstnew_add_back(tokens, NULL), ctx);
		if (*str == '\'')
			now->data = exp_create_quote_token(ctx, &str, E_SQUOTE);
		else if (*str == '\"')
			now->data = exp_create_quote_token(ctx, &str, E_DQUOTE);
		else
			now->data = exp_create_unquote_token(ctx, &str);
	}
}
