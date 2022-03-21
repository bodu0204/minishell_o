/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "ft_io.h"
#include "ft_getopt.h"
#include "ft_string.h"
#include "builtin.h"

static void	print_args(char **strs, bool *options)
{
	const bool	endl_flag = !options['n'];

	while (*strs)
	{
		ft_putstr_fd(*strs, STDOUT_FILENO);
		strs++;
		if (*strs)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (endl_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

static int	put_args(char **strs, bool *options)
{
	errno = 0;
	print_args(strs, options);
	if (errno)
	{
		perror("minishell: echo: write error");
		return (1);
	}
	else
		return (0);
}

int	blt_echo(void *ctx, size_t argc, char **argv)
{
	size_t	argvidx;
	bool	options[OPT_CHAR_MAX];

	(void)ctx;
	(void)argc;
	blt_getopt(argv, options, &argvidx, "n");
	return (put_args(&argv[argvidx], options));
}
