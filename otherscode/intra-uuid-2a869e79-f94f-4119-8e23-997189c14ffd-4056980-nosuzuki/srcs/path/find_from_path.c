/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_from_path.c                                   :+:      :+:    :+:   */
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
#include <sys/stat.h>
#include "ft_path.h"
#include "ft_string.h"
#include "error.h"
#include "wrapper.h"
#include "path.h"
#include "ft_list.h"

bool	path_dir_exists(const char *pathname)
{
	struct stat	st;

	return (stat(pathname, &st) == SYS_OK && S_ISDIR(st.st_mode));
}

bool	path_file_exists(const char *pathname)
{
	struct stat	st;

	errno = 0;
	if (stat(pathname, &st) == SYS_ERR)
		return (false);
	else if (S_ISDIR(st.st_mode))
	{
		errno = EISDIR;
		return (false);
	}
	else
		return (true);
}

// char	*path_find_from_path(void *ctx, char *name, char *paths, t_exist exist)
// {
// 	char	*paths_cpy;
// 	char	*path;
// 	char	*newpath;
// 	char	*remained;

// 	paths_cpy = or_exit(ft_strdup(paths), ctx);
// 	remained = paths_cpy;
// 	while (get_next_token(&remained, ":", &path))
// 	{
// 		newpath = ft_join_path(path, name);
// 		if (!newpath)
// 		{
// 			free(paths_cpy);
// 			or_exit(NULL, ctx);
// 		}
// 		if (exist(newpath))
// 		{
// 			free(paths_cpy);
// 			return (newpath);
// 		}
// 		free(newpath);
// 	}
// 	free(paths_cpy);
// 	return (NULL);
// }

t_clist	*path_find_files_from_path(void *ctx, char *name, char *paths)
{
	t_clist	*hits;
	char	*paths_cpy;
	char	*path;
	char	*newpath;
	char	*remained;

	hits = ft_clstnew(NULL);
	paths_cpy = or_exit(ft_strdup(paths), ctx);
	remained = paths_cpy;
	while (get_next_token(&remained, ":", &path))
	{
		newpath = or_exit(ft_join_path(path, name), ctx);
		if (path_file_exists(newpath))
			or_exit(ft_clstnew_add_back(hits, newpath), ctx);
		else
			free(newpath);
	}
	free(paths_cpy);
	return (hits);
}
