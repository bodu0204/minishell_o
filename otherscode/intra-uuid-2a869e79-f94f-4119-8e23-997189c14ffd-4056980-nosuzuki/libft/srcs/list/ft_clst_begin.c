/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_begin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdbool.h>

bool	ft_clst_isbegin(t_clist *lst)
{
	return (!lst->prev->data);
}