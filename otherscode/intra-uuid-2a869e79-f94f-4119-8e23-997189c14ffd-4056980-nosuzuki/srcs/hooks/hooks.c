/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <readline/readline.h>
#include "ft_io.h"
#include "minishell.h"
#include "variable.h"
#include "signals.h"
#include <unistd.h>

extern t_msh	g_;

int	hook_rl_reprompt(void)
{
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	var_update_exit_status(NULL, SIGINT + SIG_EXIT_OFFSET);
	return (0);
}

int	hook_rl_done(void)
{
	rl_done = g_.signum;
	return (0);
}
