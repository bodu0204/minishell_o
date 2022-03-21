/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "builtin.h"
#include "execution.h"
#include "variable.h"

char	*create_raw_cmd(void *ctx, char *cmd)
{
	if (exec_is_valid_cmd(cmd))
		return (or_exit(ft_strdup(cmd), ctx));
	else
		return (NULL);
}

static char	*find_cmd_from_path(t_exec *ctx, char *cmd)
{
	char	*envpath;
	char	*cmdpath;

	envpath = var_get_env("PATH");
	if (envpath && *envpath)
		cmdpath = exec_find_cmd_from_path(ctx, cmd, envpath);
	else
		cmdpath = create_raw_cmd(ctx, cmd);
	return (cmdpath);
}

static char	*create_cmdpath(void *ctx, char *cmd)
{
	char	*cmdpath;

	if (!ft_chr_in_str('/', cmd))
	{
		cmdpath = find_cmd_from_path(ctx, cmd);
		if (!cmdpath)
			return (NULL);
	}
	else
	{
		cmdpath = or_exit(ft_strdup(cmd), ctx);
		if (!exec_is_valid_cmd(cmdpath))
		{
			free(cmdpath);
			return (NULL);
		}
	}
	return (cmdpath);
}

static bool	specify_cmd_type(void *ctx, char *cmd, t_cmdtype *type)
{
	char	*cmdpath;

	*type = (t_cmdtype){};
	if (exec_find_builtin_func(cmd))
		type->is_builtin = true;
	else
	{
		cmdpath = create_cmdpath(ctx, cmd);
		if (!cmdpath)
			return (false);
		else
			type->cmdpath = cmdpath;
	}
	return (true);
}

bool	blt_put_cmd_type(void *ctx, char *cmd, char *bltmsg, bool is_type)
{
	bool		is_ok;
	t_cmdtype	type;

	is_ok = true;
	if (specify_cmd_type(ctx, cmd, &type))
	{
		if (type.is_builtin)
			ft_putstrs_fd((char *[]){cmd, bltmsg, NULL}, STDOUT_FILENO);
		else
		{
			if (is_type)
			{
				ft_putstr_fd(cmd, STDOUT_FILENO);
				ft_putstr_fd(" is ", STDOUT_FILENO);
			}
			ft_putendl_fd(type.cmdpath, STDOUT_FILENO);
		}
	}
	else
	{
		msh_puterrs((char *[]){cmd, ": not found", NULL});
		is_ok = false;
	}
	free(type.cmdpath);
	return (is_ok);
}
