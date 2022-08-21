/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdint.h>

uint64_t	hash_gen_fnv1a(char *s)
{
	static const uint64_t	offset = 14695981039346656037UL;
	static const uint64_t	prime = 1099511628211UL;
	uint64_t				hash;
	uint8_t					byte;

	hash = offset;
	while (*s)
	{
		byte = *s;
		hash ^= byte;
		hash *= prime;
		s++;
	}
	return (hash);
}
