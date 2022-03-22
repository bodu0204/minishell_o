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
#include "utils.h"
#include "error.h"

bool	has_key_and_val(char *str)
{
	char	*ptr;

	ptr = ft_strpbrk(str, "=");
	if (ptr)
		return (true);
	else
		return (false);
}

size_t	get_env_key_size(char *env)
{
	size_t	len;

	len = ft_strpbrk_len(env, "+=");
	return (len);
}

char	*extract_key(char *str)
{
	char	*key;
	size_t	key_size;

	key_size = get_env_key_size(str);
	key = ft_substr(str, 0, key_size);
	if (!key)
		put_strerror_and_exit();
	return (key);
}

bool	separate_environment_variables_for_key_and_val(char *str)
{
	char	*ptr;
	char	*key;
	char	*val;

	key = extract_key(str);
	if (key == NULL)
		return (false);
	ptr = ft_strpbrk(str, "+=");
	if (ptr[0] == '=')
	{
		val = ft_strdup(ptr + 1);
		if (!val)
			put_strerror_and_exit();
		ft_setenv(key, val);
	}
	else
	{
		val = ft_getenv(key);
		join_string(&val, ptr + 2);
		ft_setenv(key, val);
	}
	return (true);
}

bool	set_only_key_as_environment_variable(char *str)
{
	char	*key;

	key = ft_strdup(str);
	if (!key)
		put_strerror_and_exit();
	ft_setenv(key, NULL);
	return (true);
}
