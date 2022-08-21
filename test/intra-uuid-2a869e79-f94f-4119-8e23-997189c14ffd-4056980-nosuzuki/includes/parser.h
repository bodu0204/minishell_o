/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "ft_list.h"
# include "execunit.h"
# include "error.h"
# include "token.h"
# include <stdbool.h>
typedef struct s_parse
{
	t_del		del;
	char		*input;
	t_tokens	*tokens;
	t_tokens	*end;
	t_token		*err_token;
	t_procs		*execs;
}	t_parse;

bool	parse_cmd(t_parse *ctx);
bool	parse_exec_unit(t_parse *ctx);
bool	parse_expr(t_parse *ctx);
bool	parse_input(t_parse *ctx);
bool	parse_isend(t_parse *ctx);
bool	parse_redir(t_parse *ctx);
bool	parse_term(t_parse *ctx);
bool	parser(char *input, t_tokens *tokens, t_procs **out_execs);
char	*parse_get_token_str(t_parse *ctx, t_token *token);
int		parse_fd(t_parse *ctx, t_token	*fd_token, t_ttype redir_type);
t_proc	*parse_create_new_execunit(t_parse *ctx);
t_rtype	parse_ttype_to_rtype(t_ttype type);
t_token	*parse_pop_token(t_parse *ctx);
t_ttype	parse_get_type(t_parse *ctx);
void	parse_append_new_cmd(t_parse *ctx);
void	parse_append_new_execunit(t_parse *ctx);
void	parse_append_new_redir(t_parse *ctx, t_redir_token *rtoken);
void	parse_err(t_parse *ctx);
void	parse_init_ctx(char *input, t_tokens *tokens, t_parse *ctx);
void	parse_print_err(t_parse *ctx);

#endif
