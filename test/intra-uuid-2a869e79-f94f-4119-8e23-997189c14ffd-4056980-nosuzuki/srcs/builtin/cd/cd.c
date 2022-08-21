/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "builtin.h"
#include "wrapper.h"
#include "variable.h"
#include "ft_string.h"
#include "del.h"
#include "ft_path.h"

static void	update_pwds(void *ctx, char *newcwd)
{
	var_set_env(ctx, "OLDPWD", var_get_env("PWD"));
	var_set_env(ctx, "PWD", newcwd);
	var_set_sp(ctx, "cwd", newcwd);
}

static bool	try_cd(t_cd *ctx, t_paths *paths, size_t argc, char *dir)
{
	if (argc == 1)
		return (try_cd_to_home(ctx, paths));
	else
		return (try_cd_to_arg(ctx, paths, dir));
}

static int	change_dir(t_cd *ctx, t_paths *paths, size_t argc, char *dir)
{
	int		status;
	char	*errstr;

	if (try_cd(ctx, paths, argc, dir) || retry_cd(ctx, paths))
	{
		update_pwds(ctx, paths->newcwd);
		status = 0;
	}
	else
	{
		errstr = strerror(errno);
		msh_puterrs((char *[]){"cd: ", paths->raw_path, ": ", errstr, NULL});
		status = 1;
	}
	del_paths(paths);
	return (status);
}

int	blt_cd(void *ctx, int argc, char **argv)
{
	t_cd	cd;

	cd = (t_cd){.del.func = cd_del, .ctx = ctx};
	if (argc == 1 && !var_get_env("HOME"))
	{
		msh_puterr(ERR_CD_NO_HOME);
		return (1);
	}
	else if (argc > 2)
	{
		msh_puterr(ERR_CD_TOO_MANY);
		return (1);
	}
	return (change_dir(&cd, &cd.paths, argc, argv[1]));
}
