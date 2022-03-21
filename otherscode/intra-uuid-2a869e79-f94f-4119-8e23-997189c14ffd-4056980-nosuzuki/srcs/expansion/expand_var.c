/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hash.h"
#include "expansion.h"
#include "ft_list.h"
#include "ft_string.h"
#include <stdlib.h>

void	exp_expand_var_one(t_exp *exp, t_etok *token)
{
	extern t_msh	g_;
	char			*var;
	char			*key;
	char			*value;

	var = token->str;
	key = var + 1;
	if (exp_is_special_var(*key))
		value = hash_get(g_.sp_var, key);
	else
	{
		value = hash_get(g_.env, key);
		if (!value)
			value = hash_get(g_.sh_var, key);
	}
	if (!value)
		value = "";
	token->str = or_exit(ft_strdup(value), exp);
	free(var);
}

void	exp_expand_var(t_exp *exp, t_clist *tokens)
{
	t_etok		*token;

	tokens = tokens->next;
	while (!ft_clst_isend(tokens))
	{
		token = tokens->data;
		if (token->type & E_VAR)
			exp_expand_var_one(exp, token);
		tokens = tokens->next;
	}
}
