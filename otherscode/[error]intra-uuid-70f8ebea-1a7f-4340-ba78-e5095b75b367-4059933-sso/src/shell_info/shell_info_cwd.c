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

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "environment_variable.h"
#include "error.h"

// --- pwd ---
void	set_cwd(char *pwd)
{
	ft_free_ptr((void **)&g_sinfo.cwd);
	g_sinfo.cwd = pwd;
	ft_setenv(ft_strdup("PWD"), ft_strdup(pwd));
}

/**
 * @brief Return a copy of the cwd.
 * 
 * @return char* 
 */
char	*get_cwd(void)
{
	char	*cwd_copy;

	cwd_copy = ft_strdup(g_sinfo.cwd);
	if (!cwd_copy)
		put_strerror_and_exit();
	return (cwd_copy);
}

void	update_cwd(char *new_pwd)
{
	char	*old_pwd;

	old_pwd = get_cwd();
	ft_setenv(ft_strdup("OLDPWD"), old_pwd);
	set_cwd(ft_strdup(new_pwd));
}
