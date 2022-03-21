/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "token.h"
#include "ft_list.h"

bool	parse_isend(t_parse *ctx)
{
	return (ft_clst_isend(ctx->tokens));
}

t_token	*parse_pop_token(t_parse *ctx)
{
	return (ft_clst_next(&ctx->tokens));
}

t_ttype	parse_get_type(t_parse *ctx)
{
	if (parse_isend(ctx))
		return (T_ERR);
	return (((t_token *)(ctx->tokens->data))->type);
}
