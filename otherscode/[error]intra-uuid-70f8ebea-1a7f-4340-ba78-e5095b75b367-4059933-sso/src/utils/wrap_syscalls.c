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

#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include "define.h"
#include "error.h"
#include <fcntl.h>
#include "minishell.h"
#include "exec.h"
#include "libft.h"

//syscallをwrapする
//open
//TODO is it too specified?
int	wrap_open(const char *path, int oflag, mode_t mode)
{
	int	ret;

	errno = 0;
	ret = open(path, oflag, mode);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		put_err_msg(strerror(errno));
	}
	return (ret);
}

int	wrap_open_twoarg(const char *path, int oflag)
{
	int	ret;

	errno = 0;
	ret = open(path, oflag);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		put_err_msg(strerror(errno));
	}
	return (ret);
}

bool	wrap_pipe(int *pipe_in, int *pipe_out)
{
	int	ret;
	int	pipes[2];

	errno = 0;
	ret = pipe(pipes);
	if (ret == -1)
	{
		put_strerror_and_exit();
	}
	*pipe_in = pipes[READ];
	*pipe_out = pipes[WRITE];
	return (ret);
}

int	wrap_dup2(int oldfd, int newfd)
{
	int	ret;

	errno = 0;
	ret = dup2(oldfd, newfd);
	if (ret == -1)
	{
		put_err_msg(strerror(errno));
	}
	return (ret);
}

pid_t	wrap_fork(void)
{
	pid_t	pid;

	errno = 0;
	pid = fork();
	if (pid == -1)
	{
		put_err_msg(strerror(errno));
		put_strerror_and_exit();
	}
	return (pid);
}
