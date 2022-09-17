/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolB.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:15:14 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	list_len(char **l)
{
	size_t	i;

	if (!l)
		return (0);
	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	free_list(char	**p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return ;
}

void	*free_return(void *p, void *r)
{
	if (p)
		free(p);
	return (r);
}

void	*free_list_return(void *l, void *r)
{
	if (l)
		free_list(l);
	return (r);
}

int	ep3(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	return (1);
}
