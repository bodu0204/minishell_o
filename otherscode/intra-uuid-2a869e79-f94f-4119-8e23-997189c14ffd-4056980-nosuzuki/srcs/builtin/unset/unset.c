/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_string.h"
#include "builtin.h"
#include "minishell.h"
#include "error.h"
#include "variable.h"
#include "hash.h"
#include "cache.h"

extern t_msh	g_;

static bool	blt_unset_one(char *arg)
{
	if (!var_is_valid_name(arg))
	{
		msh_puterrs((char *[]) \
			{ERR_UNSET_INVAL1, arg, ERR_UNSET_INVAL2, NULL});
		return (false);
	}
	hash_del(g_.env, arg);
	if (ft_streq(arg, "PATH"))
		cache_clear();
	return (true);
}

static bool	blt_unset_all(size_t argc, char **argv)
{
	bool	is_all_ok;
	size_t	i;

	is_all_ok = true;
	i = 1;
	while (i < argc)
	{
		is_all_ok &= blt_unset_one(argv[i]);
		i++;
	}
	return (is_all_ok);
}

int	blt_unset(void *ctx, size_t argc, char **argv)
{
	bool	is_ok;

	(void)ctx;
	is_ok = blt_unset_all(argc, argv);
	if (!is_ok)
		return (1);
	return (0);
}
