/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "wrapper.h"
#include "execution.h"
#include "ft_list.h"
#include "ft_io.h"

bool	exec_redir_one(t_redir *redir)
{
	if (redir->type == R_HDOC)
		return (exec_hdoc(redir));
	else
		return (exec_redir_file(redir));
}

bool	exec_redir_all(t_redirs *redirs)
{
	redirs = ft_clstfirst(redirs);
	while (!ft_clst_isend(redirs))
	{
		if (!exec_redir_one(redirs->data))
			return (false);
		redirs = redirs->next;
	}
	return (true);
}

bool	exec_redir(t_proc *proc)
{
	if (exec_redir_all(proc->redirs))
		return (true);
	else
	{
		proc->error_status = 1;
		return (false);
	}
}
