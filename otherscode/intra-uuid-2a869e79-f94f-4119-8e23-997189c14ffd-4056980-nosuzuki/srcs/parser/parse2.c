/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "execunit.h"
#include "ft_list.h"
#include "ft_string.h"
#include <stdbool.h>

bool	parse_exec_unit(t_parse *ctx)
{
	if (parse_term(ctx))
	{
		while (parse_term(ctx))
			;
		return (true);
	}
	return (false);
}

bool	parse_term(t_parse *ctx)
{
	return (parse_cmd(ctx) || parse_redir(ctx));
}

bool	parse_cmd(t_parse *ctx)
{
	if (parse_get_type(ctx) & T_STR)
	{
		parse_append_new_cmd(ctx);
		parse_pop_token(ctx);
		return (true);
	}
	return (false);
}

bool	parse_redir(t_parse *ctx)
{
	t_redir_token	rtoken;

	rtoken = (t_redir_token){};
	if (parse_get_type(ctx) & T_FD)
		rtoken.fd = parse_pop_token(ctx);
	if (parse_get_type(ctx) & T_REDIR)
	{
		rtoken.redir_type = parse_pop_token(ctx);
		if (parse_get_type(ctx) & T_STR)
		{
			rtoken.filename = parse_pop_token(ctx);
			parse_append_new_redir(ctx, &rtoken);
			return (true);
		}
		else
		{
			parse_err(ctx);
			return (false);
		}
	}
	return (false);
}
