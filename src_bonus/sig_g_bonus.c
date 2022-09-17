/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_g_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:49:05 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

extern t_g	g_;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_.status == READING)
	{
		printf ("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	sigquit_handler(int sig)
{
	(void)sig;
	if (g_.status == READING)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}
