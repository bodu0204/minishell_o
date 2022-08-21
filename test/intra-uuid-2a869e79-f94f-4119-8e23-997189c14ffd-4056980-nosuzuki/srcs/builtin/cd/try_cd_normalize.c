/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_cd_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"
#include "variable.h"
#include "path.h"
#include "wrapper.h"
#include "builtin.h"
#include "ft_path.h"

static char	*create_newcwd(void *ctx, char *raw_path)
{
	char	*cwd;
	char	*cd_dest;

	cwd = var_get_sp("cwd");
	if (cwd)
		cd_dest = or_exit(path_join_with_normalize(cwd, raw_path), ctx);
	else
		cd_dest = or_exit(ft_strdup(raw_path), ctx);
	return (cd_dest);
}

static char	*create_cd_dest(void *ctx, char *raw_path)
{
	char	*cwd;
	char	*cd_dest;

	cwd = var_get_sp("cwd");
	if (cwd)
		cd_dest = or_exit(ft_join_path(cwd, raw_path), ctx);
	else
	{
		msh_put_nocurrent_err("chdir");
		cd_dest = or_exit(ft_strdup(raw_path), ctx);
	}
	return (cd_dest);
}

bool	try_cd_with_normalize(t_cd *ctx, t_paths *paths, char *raw_path)
{
	char	*cd_dest;

	cd_dest = create_cd_dest(ctx, raw_path);
	errno = 0;
	if (chdir(cd_dest) == SYS_OK)
	{
		free(cd_dest);
		paths->newcwd = create_newcwd(ctx, raw_path);
		return (true);
	}
	else
	{
		free(cd_dest);
		return (false);
	}
}
