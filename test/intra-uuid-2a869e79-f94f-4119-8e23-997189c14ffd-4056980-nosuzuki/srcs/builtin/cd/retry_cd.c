/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "ft_string.h"
#include "ft_path.h"
#include "error.h"
#include "builtin.h"
#include "wrapper.h"
#include "variable.h"

static char	*create_newcwd(void *ctx, char *raw_path)
{
	char	*cwd;
	char	*newcwd;

	cwd = ft_getcwd(ctx, "cd", NULL, 0);
	if (cwd)
	{
		newcwd = cwd;
	}
	else
	{
		cwd = var_get_sp("cwd");
		newcwd = or_exit(ft_join_path(cwd, raw_path), ctx);
	}
	return (newcwd);
}

bool	retry_cd(t_cd *ctx, t_paths *paths)
{
	int		saved_errno;

	saved_errno = errno;
	if (chdir(paths->raw_path) == SYS_OK)
	{
		if (var_get_sp("cwd"))
			paths->newcwd = create_newcwd(ctx, paths->raw_path);
		else
			paths->newcwd = or_exit(ft_strdup(paths->raw_path), ctx);
		return (true);
	}
	else
	{
		errno = saved_errno;
		return (false);
	}
}
