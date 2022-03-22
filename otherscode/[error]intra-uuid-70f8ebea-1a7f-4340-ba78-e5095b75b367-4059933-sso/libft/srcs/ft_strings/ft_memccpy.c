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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		uc;
	unsigned char		*udst;
	const unsigned char	*usrc;

	uc = (unsigned char)c;
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	while (n > 0)
	{
		if (*usrc == uc)
		{
			*udst++ = *usrc++;
			return (udst);
		}
		*udst++ = *usrc++;
		n--;
	}
	return (NULL);
}
