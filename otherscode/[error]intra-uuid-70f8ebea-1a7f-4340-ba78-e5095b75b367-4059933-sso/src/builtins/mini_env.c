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
#include "libft.h"
#include "environment_variable.h"
#include "utils.h"
#include "error.h"

static void	print_env(void *ptr)
{
	t_env_tuple	*env;

	env = ptr;
	if (env->val == NULL)
		return ;
	ft_putstr_fd(env->key, STDOUT_FILENO);
	ft_putstr_fd("=", STDOUT_FILENO);
	ft_putendl_fd(env->val, STDOUT_FILENO);
	return ;
}

int	mini_env(char **argv)
{
	t_dlst	*env_dlst;

	(void)argv;
	env_dlst = get_env_dlst();
	ft_dlstiter(env_dlst, &print_env);
	return (EX_SUCCESS);
}
