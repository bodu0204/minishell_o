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

#include "exec.h"

#include <stdio.h>
#include "libft.h"
#include "utils.h"

// exec builtin cmds or normal cmds;
int	exec_command(char **argv)
{
	int	exit_ret;

	if (!ft_dstrsize((const char **)argv))
		exit(0);
	if (is_builtin(*argv))
		exit_ret = exec_builtin(argv);
	else
		exit_ret = ft_execvp(argv);
	return (exit_ret);
}
