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
#include "environment_variable.h"
#include "error.h"

// --- status ---
void	set_exit_status(int status)
{
	g_sinfo.exit_status = status & 255;
}

int	get_exit_status(void)
{
	return (g_sinfo.exit_status);
}

bool	init_shell_info(char **envp)
{
	char	*cwd;

	g_sinfo.cwd = NULL;
	g_sinfo.env_dlst = NULL;
	set_interactive(isatty(STDIN_FILENO));
	set_exit_status(0);
	set_sig(0);
	if (!construct_env_dlst(&(g_sinfo.env_dlst), envp))
		return (false);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		err_exit("minish: error retrieving current directory");
	g_sinfo.cwd = cwd;
	return (true);
}
