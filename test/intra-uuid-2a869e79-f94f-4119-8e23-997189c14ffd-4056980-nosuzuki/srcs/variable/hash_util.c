/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "ft_string.h"
#include "hash.h"

bool	hash_append_value(t_hash *hash, char *key, char *value)
{
	char	*old_value;
	char	*new_value;
	bool	is_ok;

	old_value = hash_get(hash, key);
	if (old_value)
		new_value = ft_strjoin(old_value, value);
	else
		new_value = ft_strdup(value);
	if (!new_value)
		return (false);
	is_ok = hash_add(hash, key, new_value);
	if (!is_ok)
		free(new_value);
	return (is_ok);
}
