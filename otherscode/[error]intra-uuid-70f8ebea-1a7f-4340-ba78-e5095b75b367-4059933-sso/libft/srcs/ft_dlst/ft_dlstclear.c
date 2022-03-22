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

void	ft_dlstclear(t_dlst **dlst, void (*del)(void *))
{
	t_dlst	*next;
	t_dlst	*tmp;

	if (dlst == NULL || *dlst == NULL)
		return ;
	tmp = (*dlst)->next;
	(*dlst)->next = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		ft_dlstdelone(tmp, del);
		tmp = next;
	}
	*dlst = NULL;
}
