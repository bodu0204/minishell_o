/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "ft_list.h"
#include "execution.h"
#include "execunit.h"
#include "error.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdbool.h>
#include "ft_string.h"
#include "ft_ctype.h"
#include "del.h"

t_etok	*exp_create_var_token(void *ctx, char **str, t_etype ty)
{
	char	*start;
	char	*end;
	size_t	len;

	start = *str;
	end = start + 1;
	if (exp_is_special_var(*end))
		end++;
	else
		while (*end && exp_is_var_char(*end))
			end++;
	len = end - start;
	*str = end;
	return (exp_create_token(ctx, E_VAR | ty, len, start));
}

t_etok	*exp_create_literal_token(void *ctx, char **str, t_etype ty)
{
	char	*start;
	char	*end;
	size_t	len;

	start = *str;
	end = start;
	if (*end == '$')
		end++;
	while (*end && *end != '$')
		end++;
	len = end - start;
	*str = end;
	return (exp_create_token(ctx, E_LITERAL | ty, len, start));
}

void	exp_split_token(void *ctx, t_clist *tokens, t_etok *token)
{
	const bool		exist_next = tokens->next->data != NULL;
	t_clist			*new;
	char			*str;
	t_etype			type;
	bool			is_ignorable;

	type = token->type;
	str = token->str;
	while (true)
	{
		is_ignorable = !ft_strcmp(str, "$") && type == E_UNQUOTE && exist_next;
		if (is_ignorable)
			break ;
		new = or_exit(ft_clstnew(NULL), ctx);
		ft_clst_insert(tokens, new);
		if (type != E_SQUOTE && exp_is_var(str))
			new->data = exp_create_var_token(ctx, &str, type);
		else
			new->data = exp_create_literal_token(ctx, &str, type);
		tokens = tokens->next;
		if (!*str)
			break ;
	}
}

void	exp_tokenize_var(void *ctx, t_clist *tokens)
{
	t_etok	*token;
	t_clist	*next;

	tokens = tokens->next;
	while (!ft_clst_isend(tokens))
	{
		token = tokens->data;
		next = tokens->next;
		exp_split_token(ctx, tokens, token);
		ft_clst_popdel(tokens, msh_del);
		tokens = next;
	}
}
