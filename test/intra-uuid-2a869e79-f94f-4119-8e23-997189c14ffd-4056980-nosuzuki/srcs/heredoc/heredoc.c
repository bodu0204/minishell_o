/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "ft_utils.h"
#include "variable.h"
#include "minishell.h"
#include "parser.h"
#include "ft_string.h"
#include "ft_list.h"
#include "ft_io.h"
#include "execunit.h"
#include "error.h"
#include "heredoc.h"
#include "expansion.h"
#include "execution.h"
#include "hooks.h"
#include "signals.h"
#include "del.h"

#define MAX_HDOC_COUNT 16

extern t_msh	g_;

static bool	hdoc_input(t_hdoc *hdoc, t_redir *redir)
{
	bool	is_ok;

	hdoc_format_delimiter(hdoc, redir);
	hdoc->lines = or_exit(ft_clstnew(NULL), hdoc);
	is_ok = hdoc_input_lines(hdoc, redir->delim);
	if (is_ok)
		redir->hdoc = hdoc_join_lines(hdoc, hdoc->lines);
	ft_clst_clear(&hdoc->lines, free);
	return (is_ok);
}

static bool	hdoc_input_all(t_hdoc *hdoc, t_procs *procs)
{
	t_redir		*redir;
	t_redirs	*redirs;
	t_proc		*proc;
	bool		is_ok;

	is_ok = true;
	procs = procs->next;
	while (!ft_clst_isend(procs) && is_ok)
	{
		proc = procs->data;
		redirs = proc->redirs->next;
		while (!ft_clst_isend(redirs) && is_ok)
		{
			redir = redirs->data;
			if (redir->type == R_HDOC)
				is_ok = hdoc_input(hdoc, redirs->data);
			redirs = redirs->next;
		}
		procs = procs->next;
	}
	return (is_ok);
}

size_t	hdoc_count(t_procs *procs)
{
	size_t		count;
	t_redir		*redir;
	t_redirs	*redirs;
	t_proc		*proc;

	count = 0;
	procs = procs->next;
	while (!ft_clst_isend(procs))
	{
		proc = procs->data;
		redirs = proc->redirs->next;
		while (!ft_clst_isend(redirs))
		{
			redir = redirs->data;
			if (redir->type == R_HDOC)
				count++;
			redirs = redirs->next;
		}
		procs = procs->next;
	}
	return (count);
}

bool	heredoc(t_procs *procs)
{
	t_hdoc	hdoc;
	bool	is_ok;

	hdoc = (t_hdoc){.del.func = hdoc_del, .procs = procs};
	if (hdoc_count(procs) > MAX_HDOC_COUNT)
	{
		msh_puterr(ERR_HDOC_COUNT);
		exit(2);
	}
	rl_event_hook = hook_rl_done;
	is_ok = hdoc_input_all(&hdoc, hdoc.procs);
	rl_event_hook = NULL;
	if (!is_ok)
		var_update_exit_status(&hdoc, SIGINT + SIG_EXIT_OFFSET);
	return (is_ok);
}
