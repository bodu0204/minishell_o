/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "builtin.h"

#define BLTMSG " is a shell builtin\n"

int	blt_type(void *ctx, size_t argc, char **argv)
{
	size_t	i;
	bool	is_ok;

	is_ok = true;
	i = 1;
	while (i < argc)
	{
		is_ok &= blt_put_cmd_type(ctx, argv[i], BLTMSG, true);
		i++;
	}
	return (!is_ok);
}
