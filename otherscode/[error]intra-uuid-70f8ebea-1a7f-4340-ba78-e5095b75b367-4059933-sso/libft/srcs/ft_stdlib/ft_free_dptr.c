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

int	ft_free_dptr(void ***ptr)
{
	size_t	i;

	if (ptr == NULL)
		return (1);
	i = 0;
	while ((*ptr)[i] != NULL)
	{
		ft_free_ptr(&(*ptr)[i]);
		i++;
	}
	free(*ptr);
	*ptr = NULL;
	return (0);
}
