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
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "shell_info.h"
#include "environment_variable.h"
#include "utils.h"
#include "error.h"

/**
 * @brief 
 * 
 * @param try_path path try to chdir
 * @param new_cwd cwd set if chdir succeeds
 * @return int chdir ret
 */
int	ft_chdir(char *try_path, char *new_cwd)
{
	errno = 0;
	if (chdir(try_path))
	{
		put_err_msg(strerror(errno));
		return (EX_FAILURE);
	}
	update_cwd(new_cwd);
	return (EX_SUCCESS);
}

int	cd_absolute_path(char *absolute_path)
{
	int		ret;
	char	*new_cwd;
	char	*tmp;

	new_cwd = create_new_cwd_path("/", absolute_path);
	if (absolute_path[1] == '/' && absolute_path[2] != '/')
	{
		tmp = new_cwd;
		new_cwd = ft_strjoin("/", tmp);
		free(tmp);
	}
	ret = ft_chdir(absolute_path, new_cwd);
	free(new_cwd);
	return (ret);
}

int	cd_relative_path(char *relative_path)
{
	int		ret;
	char	*new_cwd;
	char	*tmp;

	tmp = get_cwd();
	new_cwd = create_new_cwd_path(tmp, relative_path);
	free(tmp);
	ret = ft_chdir(relative_path, new_cwd);
	free(new_cwd);
	return (ret);
}

int	cd_launch(char *try_path)
{
	if (is_absolute_path(try_path))
		return (cd_absolute_path(try_path));
	else
		return (cd_relative_path(try_path));
}
