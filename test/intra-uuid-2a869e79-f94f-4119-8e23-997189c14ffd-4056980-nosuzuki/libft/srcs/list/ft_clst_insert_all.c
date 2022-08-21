/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_insert_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_clst_insert_all(t_clist *dest, t_clist **srcptr, void (*del)())
{
	t_clist	*src;

	src = *srcptr;
	ft_clst_link(src->prev, dest->next);
	ft_clst_link(dest, src->next);
	ft_clstdelone(src, del);
	*srcptr = NULL;
}
