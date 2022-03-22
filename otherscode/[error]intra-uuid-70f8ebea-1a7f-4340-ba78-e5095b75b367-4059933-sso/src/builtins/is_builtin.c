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

#include "builtins.h"
#include "cmd.h"
#include "exec.h"
#include "environment_variable.h"

bool	is_builtin(char	*command)
{
	if (!command)
		return (false);
	if (ft_streq(command, "cd"))
		return (true);
	if (ft_streq(command, "pwd"))
		return (true);
	if (ft_streq(command, "echo"))
		return (true);
	if (ft_streq(command, "exit"))
		return (true);
	if (ft_streq(command, "export"))
		return (true);
	if (ft_streq(command, "env"))
		return (true);
	if (ft_streq(command, "unset"))
		return (true);
	return (false);
}

int	exec_builtin(char **command)
{
	int	status;

	status = false;
	if (ft_streq(*command, "cd"))
		status = mini_cd(command);
	if (ft_streq(*command, "pwd"))
		status = mini_pwd(command);
	if (ft_streq(*command, "echo"))
		status = mini_echo(command);
	if (ft_streq(*command, "exit"))
		status = mini_exit(command);
	if (ft_streq(*command, "export"))
		status = mini_export(command);
	if (ft_streq(*command, "unset"))
		status = mini_unset(command);
	if (ft_streq(*command, "env"))
		status = mini_env(command);
	return (status);
}
