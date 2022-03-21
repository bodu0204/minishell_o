/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which.c                                            :+:      :+:    :+:   */
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

#define BLTMSG ": shell built-in command\n"

int	blt_which(void *ctx, size_t argc, char **argv)
{
	size_t	i;
	bool	is_ok;

	is_ok = true;
	i = 1;
	while (i < argc)
	{
		is_ok &= blt_put_cmd_type(ctx, argv[i], BLTMSG, false);
		i++;
	}
	return (!is_ok);
}
