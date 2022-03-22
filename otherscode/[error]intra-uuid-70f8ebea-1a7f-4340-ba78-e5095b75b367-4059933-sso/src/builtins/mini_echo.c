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

char	**n_case(char **command, bool *is_newline)
{
	int	i;

	while (*command && !ft_strncmp("-n", *command, 2))
	{
		i = 2;
		while (*(*command + i))
		{
			if (*(*command + i) != 'n')
			{
				i = 0;
				break ;
			}
			i++;
		}
		if (!i)
			break ;
		*is_newline = false;
		command++;
	}
	return (command);
}

int	mini_echo(char **command)
{
	char	*ori_loc;
	bool	is_newline;

	command++;
	is_newline = true;
	command = n_case(command, &is_newline);
	ori_loc = *command;
	while (*command)
	{
		if (ori_loc != *command)
			ft_putstr_fd(" ", STDOUT_FILENO);
		ft_putstr_fd(*command, STDOUT_FILENO);
		command++;
	}
	if (is_newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
