/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include "wrapper.h"

int	get_pipeline_infd(t_procs *proc)
{
	if (ft_clst_isbegin(proc))
		return (STDIN_FILENO);
	else
		return (ft_dup(FD_NEXT_PIPE_IN));
}

int	get_pipeline_outfd(t_pipefd *newpipe, t_procs *proc)
{
	if (ft_clst_isend(proc->next))
	{
		ft_close(newpipe->out);
		return (STDOUT_FILENO);
	}
	else
		return (newpipe->out);
}
