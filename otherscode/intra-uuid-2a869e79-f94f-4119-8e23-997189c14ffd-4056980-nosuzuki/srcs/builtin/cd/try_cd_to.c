/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_cd_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include "ft_string.h"
#include "ft_io.h"
#include "ft_path.h"
#include "variable.h"
#include "builtin.h"
#include "wrapper.h"
#include "path.h"

static bool	try_every_cdpath(t_cd *ctx, t_paths *paths, char *cdpath)
{
	char	*path;
	char	*cdpath_cpy;
	char	*remained;

	cdpath_cpy = or_exit(ft_strdup(cdpath), ctx);
	remained = cdpath_cpy;
	while (get_next_token(&remained, ":", &path))
	{
		paths->cdpath_dir = ft_join_path(path, paths->raw_path);
		if (!paths->cdpath_dir)
		{
			free(cdpath_cpy);
			or_exit(NULL, ctx);
		}
		if (try_cd_with_normalize(ctx, paths, paths->cdpath_dir))
		{
			free(cdpath_cpy);
			return (true);
		}
		free(paths->cdpath_dir);
		paths->cdpath_dir = NULL;
	}
	free(cdpath_cpy);
	return (false);
}

static bool	try_cdpath(t_cd *ctx, t_paths *paths)
{
	char		*cdpath;
	const bool	is_rootpath = paths->raw_path[0] == '/';

	cdpath = var_get_env("CDPATH");
	if (is_rootpath || !cdpath || !*cdpath)
		return (false);
	if (try_every_cdpath(ctx, paths, cdpath))
	{
		if (!ft_streq(paths->raw_path, paths->cdpath_dir))
			ft_putendl_fd(paths->newcwd, STDOUT_FILENO);
		return (true);
	}
	else
		return (false);
}

bool	try_cd_to_arg(t_cd *ctx, t_paths *paths, char *dir)
{
	paths->raw_path = dir;
	if (ft_is_relative_path(dir))
		return (try_cd_with_normalize(ctx, paths, paths->raw_path));
	else
		return (try_cdpath(ctx, paths) || \
				try_cd_with_normalize(ctx, paths, paths->raw_path));
}

bool	try_cd_to_home(t_cd *ctx, t_paths *paths)
{
	paths->raw_path = var_get_env("HOME");
	return (try_cd_with_normalize(ctx, paths, paths->raw_path));
}
