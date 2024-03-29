/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_bralen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:47:51 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

void	tk_bralen1(size_t *i, unsigned int *lv, char c);
size_t	tk_bralen2(char *cl, char c);

size_t	tk_bralen(char *cl)
{
	size_t			i;
	unsigned int	lv;

	tk_bralen1(&i, &lv, *cl);
	while ((cl[i] && cl[i] != '*' && cl[i] != ' ') || lv)
	{
		if (cl[i] == '"')
			i += tk_bralen2(cl, '"');
		else if (cl[i] == '\'')
			i += tk_bralen2(cl, '\'');
		else if (cl[i] == '\\')
			i += 2;
		else
		{
			if (cl[i] == '(')
				lv++;
			else if (cl[i] == ')')
				lv--;
			i++;
		}
	}
	return (i);
}

void	tk_bralen1(size_t *i, unsigned int *lv, char c)
{
	*lv = 0;
	*i = 0;
	if (c == '(')
	{
		*lv = 1;
		*i = 1;
	}
	return ;
}

size_t	tk_bralen2(char *cl, char c)
{
	size_t	i;

	i = 1;
	while (cl[i] != c)
		i++;
	return (i + 1);
}
