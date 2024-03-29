/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_ok_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:46:21 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "find_bonus.h"

int	fi_ok(char *str, char **l)
{
	size_t	i;
	size_t	ii;

	if (l[0][0] != '\0' && ft_strncmp(str, l[0], ft_strlen(l[0])))
		return (0);
	l++;
	if (!l[0])
		return (1);
	while (l[1])
	{
		str = ft_strstr(str, *l);
		if (!str)
			return (0);
		str += ft_strlen(*l);
		l++;
	}
	if (**l == '\0')
		return (1);
	i = ft_strlen(str);
	ii = ft_strlen(*l);
	if (i < ii)
		return (0);
	if (ft_strncmp(str + i - ii, *l, ii))
		return (0);
	return (1);
}
