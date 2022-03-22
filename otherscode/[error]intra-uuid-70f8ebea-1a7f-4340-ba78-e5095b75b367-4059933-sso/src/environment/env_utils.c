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

bool	is_valid_identifier(const char *s)
{
	size_t	i;

	if (!(ft_isalpha(s[0]) || s[0] == '_'))
		return (false);
	i = 1;
	while (s[i])
	{
		if (s[i] == '=')
			return (true);
		else if (s[i] == '+')
			return (ft_strneq(s + i, "+=", 2));
		else if (ft_isalnum(s[i]) || s[i] == '_')
			;
		else
			return (false);
		i++;
	}
	return (true);
}

bool	update_env(char *str)
{
	if (!is_valid_identifier(str))
		return (false);
	if (has_key_and_val(str))
	{
		separate_environment_variables_for_key_and_val(str);
	}
	else
	{
		set_only_key_as_environment_variable(str);
	}
	return (true);
}
