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

#include <string.h>
#include <errno.h>
#include "error.h"
#include "libft.h"

bool	has_env(char *key)
{
	t_dlst	*env_node;

	env_node = search_env_node(key);
	if (env_node)
		return (true);
	else
		return (false);
}

/**
 * @brief Finds val from key and returns a copy of it.
 * @brief If not found return empty string.
 * 
 * @param key 
 * @retval true Copy of val found. Need free.
 * @retval false char* NULL
 */
char	*ft_getenv(char *key)
{
	char	*copy_val;
	t_dlst	*env_node;

	env_node = search_env_node(key);
	if (env_node)
	{
		copy_val = ft_strdup(get_env_val(env_node->content));
		if (!copy_val)
			put_strerror_and_exit();
		return (copy_val);
	}
	else
	{
		copy_val = ft_strdup("");
		if (!copy_val)
			put_strerror_and_exit();
		return (copy_val);
	}
}
