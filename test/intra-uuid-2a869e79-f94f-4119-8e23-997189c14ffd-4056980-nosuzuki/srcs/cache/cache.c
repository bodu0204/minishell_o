/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hash.h"
#include "error.h"
#include "ft_string.h"

extern t_msh	g_;

void	cache_init(void)
{
	g_.cache = or_exit(hash_new(1), NULL);
}

void	cache_add(void *ctx, char *cmd, char *path)
{
	if (!cmd || !path || !g_.cache)
		return ;
	if (!hash_add(g_.cache, cmd, path))
		or_exit(NULL, ctx);
}

char	*cache_get(char *cmd)
{
	if (!cmd || !g_.cache)
		return (NULL);
	return (hash_get(g_.cache, cmd));
}

void	cache_clear(void)
{
	if (!g_.cache)
		return ;
	hash_clear(g_.cache);
}

bool	cache_exists(char *cmd)
{
	return (hash_exists(g_.cache, cmd));
}
