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

int	cd_launch(char *try_path);

int	cd_home(void)
{
	int		ret;
	char	*home_path;

	if (!has_env("HOME"))
	{
		put_err_msg("minish: cd: HOME not set");
		return (EX_FAILURE);
	}
	else
	{
		home_path = ft_getenv("HOME");
		ret = cd_launch(home_path);
		ft_free_ptr((void **) &home_path);
		return (ret);
	}
}

int	cd_oldpwd(void)
{
	int		ret;
	char	*oldpwd;

	if (!has_env("OLDPWD"))
	{
		put_err_msg("minish: cd: OLDPWD not set");
		return (EX_FAILURE);
	}
	else
	{
		oldpwd = ft_getenv("OLDPWD");
		ret = cd_launch(oldpwd);
		ft_free_ptr((void **) &oldpwd);
		return (ret);
	}
}

int	mini_cd(char **argv)
{
	size_t	argc;

	argc = ft_dstrsize((const char **)argv);
	if (argc < 1)
		return (EX_FAILURE);
	if (argc == 1)
		return (cd_home());
	else if (argc == 2)
	{
		if (ft_streq(argv[1], "-"))
			return (cd_oldpwd());
		else if (ft_streq(argv[1], "--"))
			return (cd_home());
		else
			return (cd_launch(argv[1]));
	}
	else
	{
		put_err_msg("minish: cd: too many arguments");
		return (EX_FAILURE);
	}
}
