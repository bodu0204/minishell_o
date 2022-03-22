/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

#include <stdio.h>
#include "environment_variable.h"
#include "utils.h"
#include "libft.h"
#include "define.h"
#include "error.h"

void	export_env(void *ptr)
{
	t_env_tuple	*env;

	env = ptr;
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(env->key, STDOUT_FILENO);
	if (env->val != NULL)
	{
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putchar_fd('"', STDOUT_FILENO);
		ft_putstr_fd(env->val, STDOUT_FILENO);
		ft_putchar_fd('"', STDOUT_FILENO);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	return ;
}

bool	print_env_lst(void)
{
	t_dlst	*env_dlst;

	env_dlst = get_env_dlst();
	ft_dlstiter(env_dlst, &export_env);
	return (true);
}

void	put_export_err_msg(char *str)
{
	ft_putstr_fd("minish: export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int	mini_export(char **argv)
{
	size_t	i;
	size_t	argc;
	bool	is_sucess;

	is_sucess = EX_SUCCESS;
	argc = ft_dstrsize((const char **)argv);
	if (argc < 1)
		return (1);
	else if (argc == 1)
		print_env_lst();
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			if (!update_env(argv[i]))
			{
				put_export_err_msg(argv[i]);
				is_sucess = EX_FAILURE;
			}
			i++;
		}
	}
	return (is_sucess);
}
