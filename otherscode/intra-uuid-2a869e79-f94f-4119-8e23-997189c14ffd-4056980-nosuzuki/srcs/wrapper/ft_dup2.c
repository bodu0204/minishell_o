/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "ft_string.h"
#include "error.h"
#include "wrapper.h"

int	ft_dup2(int oldfd, int newfd)
{
	char	*err;
	char	num[50];

	errno = 0;
	if (dup2(oldfd, newfd) == SYS_ERR)
	{
		err = strerror(errno);
		ft_itoa_buf(newfd, num);
		msh_puterrs((char *[]){num, ": ", err, NULL});
		return (-1);
	}
	return (newfd);
}
