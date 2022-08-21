/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include "minishell.h"
#include "ft_io.h"
#include "wrapper.h"

extern t_msh	g_;

void	sig_handler(int signum)
{
	g_.signum = signum;
}

bool	sig_setup(int signum, sig_t handler, int sa_flags)
{
	struct sigaction	act;

	g_.signum = 0;
	act.sa_handler = handler;
	act.sa_flags = sa_flags;
	if (sigemptyset(&act.sa_mask) == SYS_ERR)
		return (false);
	if (sigaction(signum, &act, NULL) == SYS_ERR)
		return (false);
	return (true);
}

bool	sig_init(void)
{
	return (sig_setup(SIGINT, sig_handler, SA_RESTART) && \
			sig_setup(SIGQUIT, SIG_IGN, 0));
}
