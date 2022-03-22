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

void	ft_dlstconnect(t_dlst *dest, t_dlst *src)
{
	t_dlst	*src_head;
	t_dlst	*src_tail;

	if (dest == NULL || src == NULL || src->next->content == NULL)
		return ;
	src_head = src->next;
	src_tail = src->prev;
	ft_dlst_eject(src);
	ft_dlst_link(dest->prev, src_head);
	ft_dlst_link(src_tail, dest);
}
