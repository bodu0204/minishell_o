/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execution.h"
#include "wrapper.h"
#include "stdfd.h"
#include <stdlib.h>

static const t_stdfd	g_saved_stdfd = \
	{
		.in = FD_STDIN_SAVE,
		.out = FD_STDOUT_SAVE,
		.err = FD_STDERR_SAVE,
	};

void	exec_backup_stdfd(void)
{
	static bool	is_init = false;

	if (!is_init)
	{
		ft_dup2(STDERR_FILENO, g_saved_stdfd.err);
		ft_dup2(STDOUT_FILENO, g_saved_stdfd.out);
		ft_dup2(STDIN_FILENO, g_saved_stdfd.in);
		is_init = true;
	}
}

void	exec_restore_stdfd(void)
{
	ft_dup2(g_saved_stdfd.in, STDIN_FILENO);
	ft_dup2(g_saved_stdfd.out, STDOUT_FILENO);
	ft_dup2(g_saved_stdfd.err, STDERR_FILENO);
}
