/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion.h"
#include "ft_list.h"

void	exp_del(t_exp *exp)
{
	if (!exp)
		return ;
	msh_del(&exp->ctx);
	ft_clst_clear(&exp->etokens, msh_del);
	ft_clst_clear(&exp->expanded_cmds, free);
	ft_clst_clear(&exp->expanded_files, free);
}
