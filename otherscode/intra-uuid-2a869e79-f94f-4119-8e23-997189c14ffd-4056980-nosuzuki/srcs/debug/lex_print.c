/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <lexer.h>
// #include <token.h>
// #include <ft_string.h>
// #include <stdlib.h>
// #include <color.h>
//
// static char	*type_to_str(t_ttype type)
// {
// 	if (type == T_STR)
// 		return ("T_STR");
// 	if (type == T_FD)
// 		return ("T_FD");
// 	if (type == T_PIPE)
// 		return ("T_PIPE");
// 	if (type == T_NEWLINE)
// 		return ("T_NEWLINE");
// 	if (type == T_DIGITS)
// 		return ("T_DIGITS");
// 	if (type == T_REDIR_IN)
// 		return ("T_REDIR_IN");
// 	if (type == T_REDIR_OUT)
// 		return ("T_REDIR_OUT");
// 	if (type == T_HDOC)
// 		return ("T_HDOC");
// 	if (type == T_REDIR_APP)
// 		return ("T_REDIR_APP");
// 	if (type == T_REDIR_MRG_IN)
// 		return ("T_REDIR_MRG_IN");
// 	if (type == T_REDIR_MRG_OUT)
// 		return ("T_REDIR_MRG_OUT");
// 	if (type == T_REDIR_ERR_OUT)
// 		return ("T_REDIR_ERR_OUT");
// 	if (type == T_REDIR_ERR_APP)
// 		return ("T_REDIR_ERR_APP");
// 	return (NULL);
// }
//
// void	lex_print(t_tokens *tokens)
// {
// 	t_token	*token;
// 	char	*s;
//
// 	puts(GREEN"\n==============================="RESET);
// 	puts(GREEN"==========   LEXER   =========="RESET);
// 	puts(GREEN"===============================\n"RESET);
// 	while (tokens->next->data)
// 	{
// 		token = tokens->next->data;
// 		s = ft_substr(token->start, 0, token->len);
// 		printf(CYAN" %-10s"RESET" : %s\n", type_to_str(token->type), s);
// 		free(s);
// 		tokens = tokens->next;
// 	}
// }
