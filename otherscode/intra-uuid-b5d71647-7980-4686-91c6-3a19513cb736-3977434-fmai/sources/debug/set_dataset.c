/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dataset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai      <fmai@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:11:48 by fmai              #+#    #+#             */
/*   Updated: 2022/03/09 22:11:48 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_words_passed_lexer(t_list *words)
{
	t_list	*lex;

	lex = words->next;
	while (lex != NULL)
	{
		printf("lex: %s\n", (char *)lex->content);
		lex = lex->next;
	}
}

void	print_tokens_passed_parser(t_list *tokens)
{
	int			i;
	t_cmd_block	*cmd;
	t_redirects	*rdr;

	while (tokens != NULL)
	{
		i = 0;
		cmd = tokens->content;
		printf("command: %s\n", cmd->command);
		while (cmd->args[i] != NULL)
		{
			printf("args[%d]: %s\n", i, cmd->args[i]);
			i++;
		}
		while (cmd->redirects != NULL)
		{
			rdr = cmd->redirects->content;
			printf("type: %d, target: %s\n", rdr->redirect, rdr->target);
			cmd->redirects = cmd->redirects->next;
		}
		if (tokens->next == NULL)
			break ;
		tokens = tokens->next;
	}
}

t_list	*set_dataset(char *str)
{
	t_list	*words;
	t_list	*tokens;

	words = NULL;
	tokens = NULL;
	printf("LEXER-----------\n");
	if (!lexer(str, &words))
		return (NULL);
	print_words_passed_lexer(words);
	printf("PARSER-----------\n");
	if (!parser(words, &tokens, str))
		return (NULL);
	print_tokens_passed_parser(tokens);
	printf("EXPANSION-----------\n");
	return (tokens);
}
