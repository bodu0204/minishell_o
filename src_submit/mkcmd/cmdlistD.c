/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlistD.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:13:38 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "mkcmd.h"

char	**cmdlist0(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	s = tk_std(cl, 0);
	cl = skip_tk(cl);
	if (!s)
		return (NULL);
	r = cmdlist(c, cl, ncl, ll + 1);
	if (!r || !*r)
	{
		free(s);
		return (r);
	}
	r[ll] = s;
	return (r);
}
