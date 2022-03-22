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

void	**ft_dlst_to_dptr(t_dlst **dlst)
{
	void	**dptr;
	t_dlst	*tmp;
	size_t	i;

	if (dlst == NULL || *dlst == NULL)
		return (NULL);
	dptr = malloc(sizeof(void *) * (ft_dlstsize(*dlst) + 1));
	if (dptr == NULL)
		return (NULL);
	i = 0;
	tmp = (*dlst)->next;
	while (tmp->content != NULL)
	{
		dptr[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	dptr[i] = NULL;
	ft_dlstclear(dlst, NULL);
	return (dptr);
}
