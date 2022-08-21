/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H
# include "ft_list.h"
# include "execution.h"
# include "execunit.h"
typedef struct s_del	t_del;
typedef t_clist			t_etoks;
typedef enum e_etype
{
	E_UNQUOTE = 1 << 0,
	E_DQUOTE = 1 << 1,
	E_SQUOTE = 1 << 2,
	E_VAR = 1 << 3,
	E_LITERAL = 1 << 4,
	E_SP = 1 << 5,
}	t_etype;
typedef struct s_etok
{
	t_del	del;
	t_etype	type;
	char	*str;
}	t_etok;
typedef struct s_exp
{
	t_del	del;
	void	*ctx;
	t_etoks	*etokens;
	t_clist	*expanded_cmds;
	t_clist	*expanded_files;
	bool	need_to_split;
}	t_exp;

bool	exp_assign_expanded_file(t_exp *exp, t_clist *files, t_redir *redir);
bool	exp_filename(t_exp *exp, t_redirs *redirs);
bool	exp_is_sp_token(t_etok *token);
bool	exp_is_special_var(char c);
bool	exp_is_var(char *str);
bool	exp_is_var_char(char c);
bool	exp_need_to_split(t_cmds *cmds);
bool	expansion(void *ctx, t_proc *proc);
char	*exp_join_tokens(void *ctx, t_clist **tokens);
size_t	exp_get_cmd_len(t_clist *tokens);
t_etok	*exp_create_literal_token(void *ctx, char **str, t_etype ty);
t_etok	*exp_create_no_sp_token(t_exp *exp, char **str);
t_etok	*exp_create_quote_token(void *ctx, char **str, t_etype type);
t_etok	*exp_create_sp_token(t_exp *exp);
t_etok	*exp_create_token(void *ctx, t_etype ty, size_t len, char *start);
t_etok	*exp_create_unquote_token(void *ctx, char **str);
t_etok	*exp_create_var_token(void *ctx, char **str, t_etype ty);
void	exp_assign_expanded_hdoc(t_exp *exp, t_clist *tokens, t_redir *redir);
void	exp_cmds(t_exp *exp, t_cmds *cmds);
void	exp_create_cmds_from_tokens(t_exp *exp, t_cmds *cmds, t_clist *tokens);
void	exp_create_strs_from_tokens(t_exp *exp, t_clist *strs, t_clist *tokens);
void	exp_create_tokens_from_str(t_exp *ctx, char *str, t_clist *tokens);
void	exp_del_etoken(void *etoken);
void	exp_expand_var(t_exp *exp, t_clist *tokens);
void	exp_expand_var_one(t_exp *exp, t_etok *token);
void	exp_heredoc(t_exp *exp, t_redirs *redirs);
void	exp_insert_expanded_cmds(t_cmds *cmds, t_cmds **expanded);
void	exp_skip_space(char **str);
void	exp_split_by_space(t_exp *exp, t_clist *tokens);
void	exp_split_token(void *ctx, t_clist *tokens, t_etok *token);
void	exp_tokenize_dquote(t_exp *ctx, char *str, t_clist *tokens);
void	exp_tokenize_hdoc(t_exp *ctx, char *hdoc, t_clist *tokens);
void	exp_tokenize_quote(void *ctx, char *str, t_clist *tokens);
void	exp_tokenize_sp(t_exp *exp, t_clist *tokens, t_etok *token);
void	exp_tokenize_var(void *ctx, t_clist *tokens);

#endif
