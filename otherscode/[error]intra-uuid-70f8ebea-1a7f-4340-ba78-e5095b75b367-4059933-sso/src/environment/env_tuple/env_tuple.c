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
#include <stdlib.h>
#include "libft.h"

t_env_tuple	*construct_env_tuple(char *key, char *val)
{
	t_env_tuple	*env;

	env = malloc(sizeof(t_env_tuple));
	if (!env)
		return (NULL);
	env->key = key;
	env->val = val;
	return (env);
}

void	destruct_env_tuple(void *ptr)
{
	t_env_tuple	*env;

	if (ptr == NULL)
		return ;
	env = ptr;
	ft_free_ptr((void **)&env->key);
	ft_free_ptr((void **)&env->val);
	ft_free_ptr((void **)&env);
}
