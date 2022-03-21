/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "expansion.h"
#include <stdbool.h>
#include <stdlib.h>

void	exp_create_strs_from_tokens(t_exp *exp, t_clist *strs, t_clist *tokens)
{
	t_cmds	*new;
	t_etok	*token;

	tokens = tokens->next;
	while (!ft_clst_isend(tokens))
	{
		token = tokens->data;
		if (token->type == E_SP)
			tokens = tokens->next;
		else
		{
			new = or_exit(ft_clstnew_add_back(strs, NULL), exp);
			new->data = exp_join_tokens(exp, &tokens);
		}
	}
}

void	exp_create_cmds_from_tokens(t_exp *exp, t_cmds *cmds, t_clist *tokens)
{
	exp_create_strs_from_tokens(exp, cmds, tokens);
}

void	exp_insert_expanded_cmds(t_cmds *cmds, t_cmds **expanded)
{
	ft_clst_insert_all(cmds, expanded, free);
	ft_clst_popdel(cmds, free);
}
