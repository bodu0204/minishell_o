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

#include "shell_info.h"

// --- sig ---
void	reset_sig(void)
{
	g_sinfo.sig = 0;
}

void	set_sig(int sig)
{
	g_sinfo.sig = sig;
}

int	get_sig(void)
{
	return (g_sinfo.sig);
}
