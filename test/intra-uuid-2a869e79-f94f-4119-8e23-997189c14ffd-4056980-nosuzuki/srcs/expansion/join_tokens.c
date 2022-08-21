/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "ft_list.h"
#include "error.h"
#include "expansion.h"

bool	exp_is_sp_token(t_etok *token)
{
	return (token->type == E_SP);
}

size_t	exp_get_cmd_len(t_clist *tokens)
{
	size_t	len;
	t_etok	*token;

	len = 0;
	while (!ft_clst_isend(tokens) && !exp_is_sp_token(tokens->data))
	{
		token = tokens->data;
		len += ft_strlen(token->str);
		tokens = tokens->next;
	}
	return (len);
}

char	*exp_join_tokens(void *ctx, t_clist **tokens)
{
	size_t	i;
	size_t	len;
	char	*cmd;
	t_etok	*token;
	t_clist	*now;

	now = *tokens;
	len = exp_get_cmd_len(now);
	cmd = or_exit(malloc(len + 1), ctx);
	i = 0;
	while (!ft_clst_isend(now) && !exp_is_sp_token(now->data))
	{
		token = now->data;
		i += ft_strlcpy(cmd + i, token->str, len + 1);
		now = now->next;
	}
	cmd[i] = '\0';
	*tokens = now;
	return (cmd);
}
