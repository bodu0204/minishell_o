/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "ft_string.h"
#include "error.h"

bool	util_strtol(void *ctx, char *src, long *n)
{
	char	*numstr;
	bool	is_number;

	*n = 0;
	if (!src)
		return (false);
	numstr = or_exit(ft_strtrim(src, "\t "), ctx);
	is_number = ft_atol(numstr, n);
	free(numstr);
	return (is_number);
}
