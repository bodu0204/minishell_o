/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "pipefd.h"
#include "wrapper.h"

int	ft_pipe(t_pipefd *fd)
{
	int		fds[2];

	errno = 0;
	if (pipe(fds) == SYS_ERR)
	{
		perror("minishell");
		return (SYS_ERR);
	}
	fd->in = fds[0];
	fd->out = fds[1];
	return (SYS_OK);
}
