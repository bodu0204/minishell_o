/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include "hash.h"
#include "wrapper.h"
#include "ft_string.h"
#include "ft_path.h"
#include "path.h"
#include "error.h"
#include "minishell.h"
#include "variable.h"
#include "ft_utils.h"
#include "del.h"

extern t_msh	g_;

static bool	is_same_inode(const char *path1, const char *path2)
{
	struct stat	st1;
	struct stat	st2;

	errno = 0;
	if (stat(path1, &st1) == SYS_ERR || \
		stat(path2, &st2) == SYS_ERR)
		return (false);
	return (st1.st_ino == st2.st_ino);
}

void	var_update_pwd(void)
{
	char	*cwd;
	char	*envpwd;

	envpwd = var_get_env("PWD");
	cwd = var_get_sp("cwd");
	if (!is_same_inode(envpwd, cwd))
		var_set_env(NULL, "PWD", cwd);
}

void	var_init_cwd(void)
{
	t_cwd	cwd;
	char	*envpwd;
	bool	is_link;
	bool	is_same_dir;

	cwd.del.func = cwd_del;
	cwd.path = ft_getcwd(NULL, "shell-init", NULL, 0);
	if (!cwd.path)
		return ;
	envpwd = var_get_env("PWD");
	is_same_dir = envpwd && is_same_inode(envpwd, cwd.path);
	is_link = is_same_dir && !ft_streq(envpwd, cwd.path);
	if (is_link)
	{
		free(cwd.path);
		cwd.path = path_create_absolute(NULL, envpwd);
	}
	var_set_sp(&cwd, "cwd", cwd.path);
	free(cwd.path);
}
