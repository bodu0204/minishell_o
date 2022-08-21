/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "ft_list.h"
#include "lexer.h"
#include "del.h"

t_etok	*exp_create_no_sp_token(t_exp *exp, char **str)
{
	char	*start;

	start = *str;
	while (**str && !lex_isspace(**str))
		(*str)++;
	return (exp_create_token(exp, E_LITERAL, *str - start, start));
}

t_etok	*exp_create_sp_token(t_exp *exp)
{
	return (exp_create_token(exp, E_SP, 1, " "));
}

void	exp_skip_space(char **str)
{
	while (lex_isspace(**str))
		(*str)++;
}

void	exp_tokenize_sp(t_exp *exp, t_clist *tokens, t_etok *token)
{
	t_clist	*now;
	t_clist	*new;
	char	*str;

	now = tokens;
	str = token->str;
	while (*str)
	{
		new = or_exit(ft_clstnew(NULL), exp);
		ft_clst_insert(now, new);
		if (lex_isspace(*str))
		{
			new->data = exp_create_sp_token(exp);
			exp_skip_space(&str);
		}
		else
			new->data = exp_create_no_sp_token(exp, &str);
		now = now->next;
	}
	ft_clst_popdel(tokens, msh_del);
}

void	exp_split_by_space(t_exp *exp, t_clist *tokens)
{
	t_clist	*next;
	t_etok	*token;

	tokens = tokens->next;
	while (!ft_clst_isend(tokens))
	{
		next = tokens->next;
		token = tokens->data;
		if (token->type & E_UNQUOTE)
			exp_tokenize_sp(exp, tokens, token);
		tokens = next;
	}
}
