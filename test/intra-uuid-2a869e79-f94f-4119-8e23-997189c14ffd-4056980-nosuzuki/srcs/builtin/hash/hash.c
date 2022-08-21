/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_getopt.h"
#include "ft_string.h"
#include "cache.h"
#include "hash.h"
#include "minishell.h"
#include "variable.h"
#include "builtin.h"

extern t_msh	g_;

static void	put_commands(void)
{
	t_kvp	*kvp;

	if (g_.cache->count == 0)
	{
		ft_putendl_fd("hash: hash table empty", STDOUT_FILENO);
		return ;
	}
	ft_putendl_fd("command", STDOUT_FILENO);
	hash_init_get_all_kvp(g_.cache);
	kvp = hash_get_all_kvp(g_.cache);
	while (kvp)
	{
		ft_putendl_fd(kvp->value, STDOUT_FILENO);
		kvp = hash_get_all_kvp(g_.cache);
	}
}

int	blt_hash(void *ctx, size_t argc, char **argv)
{
	size_t	argvidx;
	bool	options[OPT_CHAR_MAX];
	bool	reset_flag;

	(void)ctx;
	(void)argc;
	blt_getopt(argv, options, &argvidx, "r");
	reset_flag = options['r'];
	if (reset_flag)
		cache_clear();
	else
		put_commands();
	return (0);
}
