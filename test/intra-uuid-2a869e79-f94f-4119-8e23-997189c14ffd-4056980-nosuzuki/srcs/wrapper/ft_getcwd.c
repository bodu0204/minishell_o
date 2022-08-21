/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include "error.h"

char	*ft_getcwd(void *ctx, char *errplace, char *buf, size_t size)
{
	char	*cwd;

	errno = 0;
	cwd = getcwd(buf, size);
	if (errno == ENOMEM)
		or_exit(NULL, ctx);
	else if (errno == ENOENT)
	{
		msh_put_nocurrent_err(errplace);
		return (NULL);
	}
	else if (errno)
	{
		perror("getcwd");
		return (NULL);
	}
	return (cwd);
}
