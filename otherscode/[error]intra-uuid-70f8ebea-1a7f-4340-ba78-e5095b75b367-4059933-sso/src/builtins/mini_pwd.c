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

#include <stdio.h>
#include "shell_info.h"
#include "libft.h"
#include "error.h"

int	mini_pwd(char **argv)
{
	char	*cwd;

	(void)argv;
	cwd = get_cwd();
	ft_putendl_fd(cwd, STDOUT_FILENO);
	ft_free_ptr((void **)&cwd);
	return (EX_SUCCESS);
}
