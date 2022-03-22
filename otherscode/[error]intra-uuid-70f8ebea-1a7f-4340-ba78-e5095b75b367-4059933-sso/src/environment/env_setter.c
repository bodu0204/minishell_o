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

#include "environment_variable.h"

#include <stdio.h>
#include "libft.h"
#include "error.h"

// int setenv(const char *name, const char *value, int overwrite);
/**
 * @brief Add to the list of environment variables.
 * 
 * @param key 
 * @param val 
 * @return true 
 * @return false 
 */
bool	ft_setenv(char *key, char *val)
{
	t_dlst		*env_node;
	t_env_tuple	*env;

	env = construct_env_tuple(key, val);
	if (!env)
		put_strerror_and_exit();
	env_node = ft_dlstnew(env);
	if (!env_node)
	{
		destruct_env_tuple(env);
		put_strerror_and_exit();
	}
	insert_to_env_dlst(env_node);
	return (true);
}

/**
 * @brief Find and free nodes with matching keys in the environment variable list
 * 
 * @param key 
 */
void	ft_unsetenv(char *key)
{
	t_dlst	*env_node;

	env_node = search_env_node(key);
	if (env_node == NULL)
		return ;
	ft_dlst_eject(env_node);
	destruct_env_dslt(&env_node);
}
