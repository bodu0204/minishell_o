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

#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "shell_info.h"
#include "environment_variable.h"
#include "utils.h"
#include "error.h"

char	*get_env_str(t_env_tuple *env)
{
	char	*key;
	char	*val;
	char	*tmp;
	char	*env_str;

	key = get_env_key(env);
	val = get_env_val(env);
	if (key && val)
	{
		tmp = ft_strjoin(key, "=");
		if (!tmp)
			put_strerror_and_exit();
		env_str = ft_strjoin(tmp, val);
		if (!env_str)
			put_strerror_and_exit();
		free(tmp);
		return (env_str);
	}
	return (NULL);
}

char	**get_environ(void)
{
	char	*env_str;
	char	**env;
	t_dlst	*env_dlst;
	size_t	i;
	size_t	count;

	env_dlst = get_env_dlst();
	count = ft_dlstsize(env_dlst);
	env = malloc(sizeof(char *) * (count + 1));
	if (!env)
		put_strerror_and_exit();
	i = 0;
	env_dlst = env_dlst->next;
	while (env_dlst->content)
	{
		env_str = get_env_str(env_dlst->content);
		if (env_str)
		{
			env[i] = env_str;
			i++;
		}
		env_dlst = env_dlst->next;
	}
	env[i] = NULL;
	return (env);
}
