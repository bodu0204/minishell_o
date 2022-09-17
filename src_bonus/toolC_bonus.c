/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolC_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:49:19 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	is_numustr(char *s)
{
	if (!(*s))
		return (0);
	if (*s == '-')
		s++;
	while (*s && ft_isdigit(*s))
		s++;
	if (!(*s))
		return (1);
	return (0);
}
