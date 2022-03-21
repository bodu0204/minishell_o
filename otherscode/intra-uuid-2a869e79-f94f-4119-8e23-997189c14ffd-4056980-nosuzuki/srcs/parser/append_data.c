/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "execunit.h"
#include "token.h"
#include "parser.h"
#include "ft_string.h"
#include "ft_list.h"
#include "ft_string.h"
#include "error.h"
#include "del.h"

void	parse_append_new_cmd(t_parse *ctx)
{
	t_proc	*proc;
	t_token	*token;
	char	*cmd;

	token = ctx->tokens->data;
	cmd = or_exit(ft_substr(token->start, 0, token->len), ctx);
	proc = ft_clst_last(ctx->execs)->data;
	or_exit(ft_clstnew_add_back(proc->cmds, cmd), ctx);
}

t_proc	*parse_create_new_execunit(t_parse *ctx)
{
	t_proc	*proc;

	proc = or_exit(ft_calloc(sizeof(t_proc), 1), ctx);
	proc->del.func = proc_del;
	proc->cmds = or_exit(ft_clstnew(NULL), ctx);
	proc->redirs = or_exit(ft_clstnew(NULL), ctx);
	return (proc);
}

void	parse_append_new_execunit(t_parse *ctx)
{
	t_proc	*proc;

	proc = parse_create_new_execunit(ctx);
	or_exit(ft_clstnew_add_back(ctx->execs, proc), ctx);
}

static t_redir	*parse_create_redir(t_parse *ctx, t_redir_token *rtoken)
{
	t_redir	*redir;

	redir = or_exit(ft_calloc(sizeof(t_redir), 1), ctx);
	redir->del = (t_del){.func = redir_del};
	redir->fd = parse_fd(ctx, rtoken->fd, rtoken->redir_type->type);
	redir->type = parse_ttype_to_rtype(rtoken->redir_type->type);
	redir->file = parse_get_token_str(ctx, rtoken->filename);
	return (redir);
}

void	parse_append_new_redir(t_parse *ctx, t_redir_token *rtoken)
{
	t_redir	*redir;
	t_proc	*proc;

	redir = parse_create_redir(ctx, rtoken);
	proc = ft_clst_last(ctx->execs)->data;
	or_exit(ft_clstnew_add_back(proc->redirs, redir), ctx);
}
