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

#include "environment_variable.h"
#include "shell_info.h"
#include "minishell.h"
#include "cmd.h"
#include "builtins.h"
#include "exec.h"
#include "utils.h"

char	*without_join_case(char *command)
{
	if (!ft_strchr(command, '/'))
		return (NULL);
	return (command);
}

char	*find_path(char **paths, char *command)
{
	char	*thrash_command;
	char	*joined;

	if (ft_streq("", command))
		return (NULL);
	if (!access(command, X_OK))
		return (without_join_case(command));
	thrash_command = ft_strjoin("/", command);
	while (*paths)
	{
		joined = ft_strjoin(*paths, thrash_command);
		if (!access(joined, X_OK))
		{
			free(thrash_command);
			return (joined);
		}
		free(joined);
		paths++;
	}
	free(thrash_command);
	return (NULL);
}

int	command_not_found(char *command)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

int	ft_execvp(char **command)
{
	char		**environ;
	char		*path;
	char		**splitted_path;
	char		*with_path;

	if (!*command)
		return (1);
	path = ft_getenv("PATH");
	splitted_path = ft_split(path, ':');
	free(path);
	with_path = find_path(splitted_path, *command);
	environ = get_environ();
	ft_free_dptr((void ***)&splitted_path);
	if (with_path)
	{
		execve(with_path, command, environ);
		free(with_path);
		ft_free_dptr((void ***)&environ);
	}
	else
	{
		ft_free_dptr((void ***)&environ);
		return (command_not_found(*command));
	}
	return (-1);
}
