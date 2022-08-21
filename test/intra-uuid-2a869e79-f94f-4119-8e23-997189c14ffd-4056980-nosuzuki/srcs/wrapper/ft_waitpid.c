/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <errno.h>

pid_t	ft_waitpid(pid_t pid, int *raw_status, int options)
{
	errno = 0;
	pid = waitpid(pid, raw_status, options);
	if (pid < 0 && errno != ECHILD)
		perror("minishell: waitpid:");
	return (pid);
}
