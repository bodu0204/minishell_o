/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
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

int	exec_rtype_to_oflag(t_rtype type)
{
	int	flag;

	if (type & R_OUT_BIT)
	{
		flag = O_WRONLY | O_CREAT;
		if (type & R_APP_BIT)
			flag |= O_APPEND;
		else
			flag |= O_TRUNC;
	}
	else
		flag = O_RDONLY;
	return (flag);
}

bool	exec_hdoc(t_redir *redir)
{
	t_pipefd	fd;
	bool		is_ok;

	if (ft_pipe(&fd) == SYS_ERR)
		return (false);
	is_ok = ft_dup2(fd.in, STDIN_FILENO) != SYS_ERR;
	if (is_ok)
		ft_putstr_fd(redir->hdoc, fd.out);
	exec_close_pipe(&fd);
	return (is_ok);
}

bool	exec_redir_file(t_redir *redir)
{
	bool			is_dup_ok;
	bool			is_close_ok;
	const int		flag = exec_rtype_to_oflag(redir->type);
	const mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int				fd;

	sig_setup(SIGINT, sig_handler, 0);
	fd = ft_open(redir->file, flag, mode);
	sig_setup(SIGINT, sig_handler, SA_RESTART);
	if (fd == SYS_ERR)
		return (false);
	is_dup_ok = ft_dup2(fd, redir->fd) != SYS_ERR;
	if (fd != redir->fd)
		is_close_ok = ft_close(fd) != SYS_ERR;
	else
		is_close_ok = true;
	return (is_dup_ok && is_close_ok);
}
