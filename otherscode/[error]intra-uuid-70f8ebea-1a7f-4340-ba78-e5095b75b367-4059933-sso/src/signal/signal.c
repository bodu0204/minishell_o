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

#include "signal_handler.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "shell_info.h"

void	sig_handler(int sig)
{
	g_sinfo.sig = sig;
}

void	restore_signal_handler(void)
{
	set_signal_handler(SIGQUIT, SIG_DFL, 0);
	set_signal_handler(SIGINT, SIG_DFL, 0);
}

bool	set_signal_handler(int signal, sig_t handler, int sa_flags)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = handler;
	act.sa_flags = sa_flags;
	if (sigemptyset(&act.sa_mask))
		return (false);
	if (sigaddset(&act.sa_mask, signal))
		return (false);
	if (sigaction(signal, &act, NULL))
		return (false);
	return (true);
}

bool	init_signal_handler(void)
{
	if (!set_signal_handler(SIGQUIT, SIG_IGN, 0))
		return (false);
	if (is_interactive())
	{
		if (!set_signal_handler(SIGINT, sig_handler, SA_RESTART))
			return (false);
	}
	return (true);
}
