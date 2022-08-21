/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "token.h"
# include "ft_list.h"
# include "error.h"
# include <stdbool.h>
typedef struct s_lex
{
	t_del		del;
	char		*input;
	size_t		idx;
	t_tokens	*tokens;
}	t_lex;

bool	lex_is_fd(t_token *now, t_token *next);
bool	lex_isop(char c);
bool	lex_isquote(char c);
bool	lex_isspace(char c);
bool	lex_isspecial(char c);
bool	lex_tokenize(t_lex *lex);
bool	lex_tokenize_literal(t_lex *lex);
bool	lex_tokenize_op(t_lex *lex);
bool	lex_tokenize_sp(t_lex *lex);
bool	lexer(char *input, t_tokens **out_tokens);
void	lex_add_newtok(t_ttype type, const char *start, size_t len, t_lex *lex);
void	lex_assign_fd_token(t_lex *lex);
void	lex_correct_digits_token(t_lex *lex);
void	lex_remove_sp_token(t_lex *lex);

#endif
