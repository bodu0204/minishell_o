/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ft_io.h"
#include "ft_string.h"
#include "ft_free.h"
#include "ft_utils.h"
#include "ft_path.h"
#include "path.h"
#include "execution.h"
#include "error.h"
#include "wrapper.h"
#include "variable.h"
#include "cache.h"

//still reachable paths

static char	*find_cmd_from_path(t_exec *ctx, char *cmd)
{
	char	*envpath;
	char	*cmdpath;

	envpath = var_get_env("PATH");
	if (envpath && *envpath)
		cmdpath = exec_find_cmd_from_path(ctx, cmd, envpath);
	else
		cmdpath = or_exit(ft_strdup(cmd), ctx);
	return (cmdpath);
}

char	*exec_find_cmd_from_path_hndl_err(t_exec *ctx, t_proc *proc, char *cmd)
{
	char	*cmdpath;

	cmdpath = find_cmd_from_path(ctx, cmd);
	if (!cmdpath)
	{
		ft_puterr((char *[]){cmd, ERR_CMD_NOT_FOUND, NULL});
		proc->error_status = ST_ERR_NOT_FOUND;
	}
	else if (!exec_is_valid_cmd(cmdpath))
	{
		exec_hndle_invalid_cmd_err(proc, cmdpath);
		free(cmdpath);
		return (NULL);
	}
	return (cmdpath);
}

char	*exec_create_cmdpath(t_exec *ctx, t_proc *proc, char *cmd)
{
	char	*cmdpath;

	if (!ft_chr_in_str('/', cmd))
	{
		cmdpath = exec_find_cmd_from_path_hndl_err(ctx, proc, cmd);
		if (!cmdpath)
			return (NULL);
		cache_add(ctx, cmd, cmdpath);
	}
	else
	{
		cmdpath = or_exit(ft_strdup(cmd), ctx);
		if (!exec_is_valid_cmd(cmdpath))
		{
			exec_hndle_invalid_cmd_err(proc, cmdpath);
			free(cmdpath);
			return (NULL);
		}
	}
	return (cmdpath);
}
