/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_absolute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_utils.h"
#include "ft_path.h"
#include "ft_string.h"
#include "error.h"
#include "wrapper.h"
#include "path.h"
#include "variable.h"
#include "error.h"

char	*get_current_dir(void *ctx)
{
	char		*cwd;
	const char	*cwd2 = var_get_sp("cwd");

	if (cwd2)
	{
		if (path_dir_exists(cwd2))
			cwd = or_exit(ft_strdup(var_get_sp("cwd")), ctx);
		else
		{
			msh_put_nocurrent_err("cd");
			return (NULL);
		}
	}
	else
		cwd = ft_getcwd(ctx, "chdir", NULL, 0);
	return (cwd);
}

char	*path_join_with_normalize(char *cwd, char *pathname)
{
	char	*rootpath;
	char	*fullpath;
	bool	is_two_slash_root;

	rootpath = ft_join_path(cwd, pathname);
	if (!rootpath)
		return (NULL);
	fullpath = ft_normalize_path(rootpath);
	if (!fullpath)
	{
		free(rootpath);
		return (NULL);
	}
	is_two_slash_root = !ft_strncmp(rootpath, "//", 2) && rootpath[2] != '/';
	if (is_two_slash_root)
		ft_free_assign((void **)&fullpath, ft_strjoin("/", fullpath));
	free(rootpath);
	return (fullpath);
}
//add comment -> rarely relative path

char	*path_create_absolute(void *ctx, char *pathname)
{
	char	*cwd;
	char	*fullpath;

	cwd = get_current_dir(ctx);
	if (!cwd)
		return (NULL);
	fullpath = path_join_with_normalize(cwd, pathname);
	free(cwd);
	return (or_exit(fullpath, ctx));
}
