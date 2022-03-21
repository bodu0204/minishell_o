/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
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

bool	parse_input(t_parse *ctx)
{
	if (parse_get_type(ctx) & T_NEWLINE)
	{
		parse_pop_token(ctx);
		return (true);
	}
	else if (parse_expr(ctx))
	{
		if (parse_get_type(ctx) & T_NEWLINE)
		{
			parse_pop_token(ctx);
			return (true);
		}
	}
	return (false);
}

bool	parse_expr(t_parse *ctx)
{
	parse_append_new_execunit(ctx);
	if (parse_exec_unit(ctx))
	{
		while (parse_get_type(ctx) & T_PIPE)
		{
			parse_append_new_execunit(ctx);
			parse_pop_token(ctx);
			if (!parse_exec_unit(ctx))
			{
				return (false);
			}
		}
		return (true);
	}
	return (false);
}
