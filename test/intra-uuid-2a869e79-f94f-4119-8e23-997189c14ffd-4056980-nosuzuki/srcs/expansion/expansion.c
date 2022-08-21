/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_utils.h"
#include "expansion.h"
#include "ft_list.h"
#include "execution.h"
#include "execunit.h"
#include "error.h"
#include "lexer.h"
#include "hash.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdbool.h>
#include "ft_string.h"
#include "del.h"

#include "debug.h"

bool	exp_need_to_split(t_cmds *cmds)
{
	char		*cmd;

	cmd = ft_clstfirst(cmds)->data;
	return (cmd && ft_strcmp(cmd, "export"));
}

void	exp_cmds(t_exp *exp, t_cmds *cmds)
{
	t_cmds	*next;

	exp->need_to_split = exp_need_to_split(cmds);
	cmds = ft_clstfirst(cmds);
	while (!ft_clst_isend(cmds))
	{
		next = cmds->next;
		exp->etokens = or_exit(ft_clstnew(NULL), exp);
		exp->expanded_cmds = or_exit(ft_clstnew(NULL), exp);
		exp_create_tokens_from_str(exp, cmds->data, exp->etokens);
		exp_create_cmds_from_tokens(exp, exp->expanded_cmds, exp->etokens);
		exp_insert_expanded_cmds(cmds, &exp->expanded_cmds);
		ft_clst_clear(&exp->etokens, msh_del);
		cmds = next;
	}
}

void	exp_heredoc(t_exp *exp, t_redirs *redirs)
{
	t_redir		*redir;

	redirs = redirs->next;
	while (!ft_clst_isend(redirs))
	{
		redir = redirs->data;
		if (redir->hdoc)
		{
			exp->etokens = or_exit(ft_clstnew(NULL), exp);
			exp_tokenize_hdoc(exp, redir->hdoc, exp->etokens);
			exp_assign_expanded_hdoc(exp, exp->etokens, redir);
			ft_clst_clear(&exp->etokens, msh_del);
		}
		redirs = redirs->next;
	}
}

bool	exp_filename(t_exp *exp, t_redirs *redirs)
{
	t_redir		*redir;
	bool		is_ok;

	is_ok = true;
	exp->need_to_split = true;
	redirs = redirs->next;
	while (!ft_clst_isend(redirs) && is_ok)
	{
		redir = redirs->data;
		if (!redir->hdoc)
		{
			exp->etokens = or_exit(ft_clstnew(NULL), exp);
			exp->expanded_files = or_exit(ft_clstnew(NULL), exp);
			exp_create_tokens_from_str(exp, redir->file, exp->etokens);
			exp_create_strs_from_tokens(exp, exp->expanded_files, exp->etokens);
			is_ok = exp_assign_expanded_file(exp, exp->expanded_files, redir);
			ft_clst_clear(&exp->etokens, msh_del);
			ft_clst_clear(&exp->expanded_files, free);
		}
		redirs = redirs->next;
	}
	if (!is_ok)
		msh_puterrs((char *[]){redir->file, ERR_EXP_AMBIGUOUS, NULL});
	return (is_ok);
}

bool	expansion(void *ctx, t_proc *proc)
{
	t_exp	exp;

	exp = (t_exp){.ctx = ctx, .del.func = exp_del};
	exp_cmds(&exp, proc->cmds);
	exp_heredoc(&exp, proc->redirs);
	if (!exp_filename(&exp, proc->redirs))
		proc->error_status = ST_ERR_EXPAND;
	return (proc->error_status == ST_SUCCESS);
}
