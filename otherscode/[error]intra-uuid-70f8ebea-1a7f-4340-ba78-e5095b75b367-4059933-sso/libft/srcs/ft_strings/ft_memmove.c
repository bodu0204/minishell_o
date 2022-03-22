/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (from == to || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			to[len - 1] = from[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(to, from, len);
	return (dst);
}
