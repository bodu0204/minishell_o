/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "ft_io.h"
#include "error.h"
#include "variable.h"

int	blt_pwd(void *ctx, size_t argc, char **argv)
{
	const char	*cwd = var_get_sp("cwd");

	(void)ctx;
	(void)argc;
	(void)argv;
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (0);
	}
	else
	{
		msh_put_nocurrent_err("pwd");
		return (1);
	}
}
