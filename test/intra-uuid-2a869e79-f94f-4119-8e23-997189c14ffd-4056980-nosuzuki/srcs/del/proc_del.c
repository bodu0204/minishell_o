/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_del.c                                         :+:      :+:    :+:   */
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
#include "ft_free.h"
#include "execunit.h"

void	proc_del(t_proc *proc)
{
	if (!proc)
		return ;
	free(proc->cmdpath);
	ft_free_strs(&proc->argv);
	ft_clst_clear(&proc->cmds, free);
	ft_clst_clear(&proc->redirs, msh_del);
	free(proc);
}
