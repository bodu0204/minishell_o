/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_utils.h"
#include <stdlib.h>

t_clist	*ft_clstnew(void *data)
{
	t_clist	*new;

	if (!ft_setptr(&new, malloc(sizeof(t_clist))))
		return (NULL);
	new->data = data;
	new->next = new;
	new->prev = new;
	return (new);
}
