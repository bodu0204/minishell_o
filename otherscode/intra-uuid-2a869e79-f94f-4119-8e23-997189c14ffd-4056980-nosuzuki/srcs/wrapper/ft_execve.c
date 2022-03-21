/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "wrapper.h"
#include "error.h"

int	ft_execve(const char *filename, char *const argv[], char *const envp[])
{
	errno = 0;
	if (execve(filename, argv, envp) == SYS_ERR)
	{
		msh_puterrs((char *[]){(char *)filename, ": ", strerror(errno), NULL});
		return (SYS_ERR);
	}
	return (SYS_OK);
}
