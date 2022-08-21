/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_clst_clear(t_clist **lst, void (*del)())
{
	t_clist	*now;
	t_clist	*end;
	t_clist	*next;

	if (!lst || !*lst)
		return ;
	end = *lst;
	now = (*lst)->next;
	while (now != end)
	{
		next = now->next;
		ft_clstdelone(now, del);
		now = next;
	}
	free(end);
	*lst = NULL;
}
