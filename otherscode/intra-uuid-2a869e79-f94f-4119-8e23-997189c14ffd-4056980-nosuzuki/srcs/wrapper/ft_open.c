/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "wrapper.h"
#include "error.h"
//no such file error -> filename
int	ft_open(const char *pathname, int flags, mode_t mode)
{
	int	fd;

	errno = 0;
	if (flags & O_CREAT)
		fd = open(pathname, flags, mode);
	else
		fd = open(pathname, flags);
	if (fd == SYS_ERR)
	{
		msh_puterrs((char *[]){(char *)pathname, ": ", strerror(errno), NULL});
		return (fd);
	}
	return (fd);
}
