/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "parser.h"
#include "execunit.h"
#include "ft_list.h"
#include "ft_string.h"
#include "del.h"

void	parse_init_ctx(char *input, t_tokens *tokens, t_parse *ctx)
{
	ctx->input = input;
	ctx->tokens = tokens;
	ctx->err_token = NULL;
	ctx->del = (t_del){.func = parse_del};
	ctx->end = tokens;
	ctx->execs = or_exit(ft_clstnew(NULL), ctx);
}

bool	parser(char *input, t_tokens *tokens, t_procs **out_execs)
{
	t_parse	ctx;

	*out_execs = NULL;
	parse_init_ctx(input, tokens, &ctx);
	parse_pop_token(&ctx);
	if (!parse_input(&ctx))
	{
		parse_err(&ctx);
		parse_print_err(&ctx);
		ft_clst_clear(&ctx.execs, msh_del);
		return (false);
	}
	*out_execs = ctx.execs;
	return (true);
}
