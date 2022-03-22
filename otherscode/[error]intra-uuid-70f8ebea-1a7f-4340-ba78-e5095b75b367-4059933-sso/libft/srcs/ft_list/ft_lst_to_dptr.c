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

void	**ft_lst_to_dptr(t_list **lst)
{
	void	**dptr;
	t_list	*tmp;
	size_t	i;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	dptr = malloc(sizeof(void *) * (ft_lstsize(*lst) + 1));
	if (dptr == NULL)
		return (NULL);
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		dptr[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	dptr[i] = NULL;
	ft_lstclear(lst, NULL);
	return (dptr);
}
