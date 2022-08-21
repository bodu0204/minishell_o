/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_ctype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <expansion.h>
#include "ft_ctype.h"
#include "ft_string.h"

bool	exp_is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

bool	exp_is_special_var(char c)
{
	const char	*charset = "*@#?-$!";

	return (c && (ft_isdigit(c) || ft_strchr(charset, c)));
}

bool	exp_is_var(char *str)
{
	return (str[0] == '$'
		&& (exp_is_special_var(str[1]) || exp_is_var_char(str[1])));
}
