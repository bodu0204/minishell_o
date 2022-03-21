/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_setptr(void *dest, void *p)
{
	*(uintptr_t *)dest = (uintptr_t)p;
	return (!!p);
}