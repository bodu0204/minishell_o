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

#include <stdio.h>

#include "minishell.h"
#include "shell_info.h"
#include "environment_variable.h"
#include "signal_handler.h"
#include "error.h"
#include "utl_readline.h"

t_shell_info	g_sinfo;

bool	initialize(char **envp)
{
	if (!init_shell_info(envp))
		put_strerror_and_exit();
	if (!init_signal_handler())
		put_strerror_and_exit();
	set_readline_outstream(stderr);
	return (true);
}

void	finalize(void)
{
	destruct_env_dslt(&g_sinfo.env_dlst);
	g_sinfo.env_dlst = NULL;
	free(g_sinfo.cwd);
	g_sinfo.cwd = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	if (argc != 1)
		err_exit("minish: Arguments are not accepted.");
	if (!initialize(envp))
		return (1);
	minishell();
	finalize();
	return (get_exit_status());
}
