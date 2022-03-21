/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ft_list.h"
#include "error.h"
#include "path.h"
#include "wrapper.h"

static bool	is_executable(const char *pathname)
{
	return (access(pathname, X_OK) == SYS_OK);
}

bool	exec_is_valid_cmd(char *pathname)
{
	return (path_file_exists(pathname) && is_executable(pathname));
}

static char	*find_executable_cmd(void *ctx, t_clist *cmds)
{
	char	*cmd;

	if (ft_clst_isempty(cmds))
		return (NULL);
	cmds = ft_clstfirst(cmds);
	while (!ft_clst_isend(cmds))
	{
		cmd = cmds->data;
		if (is_executable(cmd))
			return (or_exit(ft_strdup(cmd), ctx));
		cmds = cmds->next;
	}
	return (or_exit(ft_strdup(cmd), ctx));
}

char	*exec_find_cmd_from_path(void *ctx, char *cmd, char *envpath)
{
	t_clist	*hits;
	char	*cmdpath;

	hits = path_find_files_from_path(ctx, cmd, envpath);
	cmdpath = find_executable_cmd(ctx, hits);
	if (cmdpath && ft_streq(cmd, cmdpath))
	{
		free(cmdpath);
		cmdpath = or_exit(ft_strjoin("./", cmd), ctx);
	}
	ft_clst_clear(&hits, free);
	return (cmdpath);
}
