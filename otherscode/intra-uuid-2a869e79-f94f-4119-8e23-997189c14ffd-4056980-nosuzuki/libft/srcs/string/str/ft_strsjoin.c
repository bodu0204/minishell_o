/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strsjoin(char **strs)
{
	char	*dest;
	size_t	destsize;
	size_t	pos;
	size_t	i;

	i = 0;
	destsize = 1;
	while (strs[i])
	{
		destsize += ft_strlen(strs[i]);
		i++;
	}
	dest = malloc(destsize);
	if (!dest)
		return (NULL);
	i = 0;
	pos = 0;
	while (strs[i])
	{
		pos += ft_strlcpy(dest + pos, strs[i], destsize);
		i++;
	}
	dest[pos] = '\0';
	return (dest);
}
