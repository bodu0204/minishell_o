/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "ft_string.h"
#include "minishell.h"
#include "error.h"
#include "ft_free.h"
#include "ft_ctype.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern t_msh	g_;

t_kvp	**var_get_all_kvp(void *ctx, t_hash *hash)
{
	t_kvp	**all_kvp;
	t_kvp	*kvp;
	size_t	i;

	all_kvp = or_exit(ft_calloc(hash->count + 1, sizeof(t_kvp *)), ctx);
	hash_init_get_all_kvp(hash);
	kvp = hash_get_all_kvp(hash);
	i = 0;
	while (kvp)
	{
		all_kvp[i] = kvp;
		kvp = hash_get_all_kvp(hash);
		i++;
	}
	return (all_kvp);
}

char	**var_get_all_str(void *ctx, t_hash *hash)
{
	char	**all_str;
	t_kvp	*kvp;
	size_t	i;

	all_str = or_exit(ft_calloc(hash->count + 1, sizeof(char *)), ctx);
	hash_init_get_all_kvp(hash);
	kvp = hash_get_all_kvp(hash);
	i = 0;
	while (kvp)
	{
		if (kvp->value)
		{
			all_str[i] = ft_strsjoin((char *[])
				{kvp->key, "=", kvp->value, NULL});
			if (!all_str[i])
			{
				ft_free_strs(&all_str);
				or_exit(NULL, ctx);
			}
			i++;
		}
		kvp = hash_get_all_kvp(hash);
	}
	return (all_str);
}

bool	var_is_valid_name(char *name)
{
	size_t	i;

	if (ft_strlen(name) == 0)
		return (false);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (false);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
