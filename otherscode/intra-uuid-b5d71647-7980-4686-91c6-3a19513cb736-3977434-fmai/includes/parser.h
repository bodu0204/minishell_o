/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai      <fmai@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:03:08 by fmai              #+#    #+#             */
/*   Updated: 2022/03/21 23:03:08 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"

// parser/parser.c
bool		is_valid_words(t_list *words, char *str);
bool		is_redirect(t_list *words);
void		set_cmd_block(t_list **words, t_cmd_block *cmd);
void		set_tokens(t_list **tokens, t_cmd_block *cmd);
bool		parser(t_list *words, t_list **tokens, char *str);

// parser/set_args.c
int			get_args_malloc(t_cmd_block *cmd, int arg_num);
void		add_args(t_list **words, t_cmd_block *cmd, int arg_num);
void		set_args(t_list **words, t_cmd_block *cmd);

// parser/set_redirect.c
void		set_redirect_type(t_list **words, t_redirects *redir);
t_redirects	*set_redirect(t_list **words);

#endif
