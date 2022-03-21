/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_free.h"
#include "ft_io.h"
#include "minishell.h"
#include "variable.h"

extern t_msh	g_;

static void	blt_env_print(void *ctx)
{
	char	**env;
	size_t	i;

	env = var_get_all_str(ctx, g_.env);
	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	ft_free_strs(&env);
}

int	blt_env(void *ctx, size_t argc, char **argv)
{
	(void)argc;
	(void)argv;
	blt_env_print(ctx);
	return (0);
}
