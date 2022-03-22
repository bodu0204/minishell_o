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

#include "error.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "shell_info.h"

bool	set_error(int num)
{
	set_exit_status(num);
	return (false);
}

void	put_err_msg(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	put_err_msg3(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, STDERR_FILENO);
	ft_putstr_fd(s2, STDERR_FILENO);
	ft_putstr_fd(s3, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	err_exit(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	put_strerror_and_exit(void)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(1);
}
