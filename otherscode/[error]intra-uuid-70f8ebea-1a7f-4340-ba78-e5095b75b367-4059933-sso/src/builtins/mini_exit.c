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

#include "shell_info.h"
#include "error.h"

static	void	check_command(char *command)
{
	int	is_sign;

	is_sign = 0;
	while (*command)
	{
		if (!ft_isdigit(*command))
		{
			if (*command == '+' || *command == '-')
			{
				is_sign++;
				if (*(command + 1) == '\0')
					is_sign++;
			}
			else if (!ft_isdigit(*command))
				is_sign = 2;
			if (is_sign > 1)
			{
				put_err_msg("exit");
				put_err_msg("minish: exit:numeric argument required");
				exit(2);
			}
		}
		command++;
	}
}

int	mini_exit(char **command)
{
	command++;
	if (!*command)
		exit(get_exit_status());
	check_command(*command);
	if (*(command + 1))
	{
		put_err_msg("bash: exit: too many arguments\n");
		return (1);
	}
	if (ft_atoi(*command))
		exit(ft_atoi(*command));
	else
		exit(0);
}
