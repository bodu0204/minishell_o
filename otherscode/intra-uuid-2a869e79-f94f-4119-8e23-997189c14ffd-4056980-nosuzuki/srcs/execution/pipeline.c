/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_list.h"
#include "wrapper.h"
#include "execution.h"
#include "execunit.h"
#include "wrapper.h"
#include "pipefd.h"

static void	save_next_pipe_in(int next_in)
{
	ft_dup2(next_in, FD_NEXT_PIPE_IN);
	close(next_in);
}

static void	exec_init_pipeline(t_pipefd *fd, t_procs *proc)
{
	t_pipefd	newpipe;

	ft_pipe(&newpipe);
	fd->in = get_pipeline_infd(proc);
	fd->out = get_pipeline_outfd(&newpipe, proc);
	save_next_pipe_in(newpipe.in);
}

//tmp
void	exec_connect_pipe(t_pipefd *fd)
{
	ft_dup2(fd->out, STDOUT_FILENO);
	ft_dup2(fd->in, STDIN_FILENO);
}

//tmp //ifいる？
void	exec_close_pipe(t_pipefd *fd)
{
	if (fd->in != STDIN_FILENO)
		ft_close(fd->in);
	if (fd->out != STDOUT_FILENO)
		ft_close(fd->out);
}

void	exec_setup_pipe_connection(t_procs *procs)
{
	t_pipefd	pipeline;

	exec_init_pipeline(&pipeline, procs);
	exec_connect_pipe(&pipeline);
	exec_close_pipe(&pipeline);
}
