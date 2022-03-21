/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "error.h"
#include "heredoc.h"

void	hdoc_del(t_hdoc *hdoc)
{
	free((void *)hdoc->input);
	ft_clst_clear(&hdoc->lines, free);
	ft_clst_clear(&hdoc->procs, msh_del);
	ft_clst_clear(&hdoc->tokens, msh_del);
}
