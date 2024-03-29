/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlistC_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:47:35 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "mkcmd_bonus.h"

char	**cmdlist6(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	int		fd[2];

	cl = skip_tk(cl);
	pipe(fd);
	if (c->pipe[W_PIPE] >= 0)
		close(fd[W_PIPE]);
	else
		c->pipe[W_PIPE] = fd[W_PIPE];
	c->pipe[NEXT_PIPE] = fd[R_PIPE];
	r = cmdlist(c, "", ncl, ll);
	c->n_type = PIPE;
	*ncl = cl;
	return (r);
}

char	**cmdlist7(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	cl = skip_tk(cl);
	c->n_type = CONTINUE;
	r = cmdlist(c, "", ncl, ll);
	*ncl = cl;
	return (r);
}

char	**cmdlist8(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	cl = skip_tk(cl);
	r = cmdlist(c, "", ncl, ll);
	if (c->n_type != SKIP)
		c->n_type = OR;
	*ncl = cl;
	return (r);
}

char	**cmdlist9(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;

	cl = skip_tk(cl);
	r = cmdlist(c, "", ncl, ll);
	if (c->n_type != SKIP)
		c->n_type = AND;
	*ncl = cl;
	return (r);
}

char	**cmdlist10(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;
	size_t	l;

	if (ll)
	{
		r = cmdlist(c, "", ncl, ll);
		*ncl = cl;
		return (r);
	}
	l = tk_bralen(cl);
	s = malloc(l + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, cl, l);
	s[l] = '\0';
	r = cmdlist(c, cl + l, ncl, 1);
	if (!r || !*r)
	{
		free(s);
		return (r);
	}
	r[0] = s;
	return (r);
}
