/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getoptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "ft_getopt.h"
#include "ft_string.h"

void	blt_getopt(char **argv, bool *options, size_t *argvidx, char *optstr)
{
	int			opt;
	t_argopt	argopt;

	ft_bzero(options, sizeof(bool) * OPT_CHAR_MAX);
	ft_init_argopt(&argopt, argv, optstr);
	while (true)
	{
		opt = ft_getopt(&argopt);
		if (opt == -1)
			break ;
		else if (opt)
			options[opt] = true;
	}
	*argvidx = argopt.argvidx;
}
