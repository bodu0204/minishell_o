/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_io.h"
#include "error.h"
#include "ft_string.h"
#include <unistd.h>
#include <stdlib.h>

void	parse_print_err(t_parse *ctx)
{
	char			*str;
	const t_token	*err_token = ctx->err_token;

	if (!ctx->err_token)
		return ;
	str = or_exit(ft_substr(err_token->start, 0, err_token->len), ctx);
	msh_puterrs((char *[]){ERR_PARSE_SYNTAX_1, str, ERR_PARSE_SYNTAX_2, NULL});
	free(str);
}

void	parse_err(t_parse *ctx)
{
	if (ctx->err_token)
		return ;
	ctx->err_token = parse_pop_token(ctx);
	ctx->tokens = ctx->end;
}
