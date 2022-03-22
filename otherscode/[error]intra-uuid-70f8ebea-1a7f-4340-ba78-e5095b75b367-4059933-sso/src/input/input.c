/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

#include <stdio.h>
#include "libft.h"
#include "utils.h"
#include "error.h"

// input     : echo a | echo $VAR > file
// lexer     : echo a | echo $VAR > file
// paser     : [ echo a ] [ echo $VAR > file ]
// expansion : [ echo a ] [ echo HOGE > file ]

bool	analyze_input(char *command, t_dlst *token_dlst, t_dlst *cmd_dlst)
{
	if (!lexer(command, token_dlst))
		return (set_error(EX_SYNTAX));
	if (!parser(token_dlst, cmd_dlst))
		return (set_error(EX_SYNTAX));
	if (!expansion(cmd_dlst))
		return (set_error(EX_SYNTAX));
	conv_arg(cmd_dlst);
	return (true);
}

// if (!lexer(command, token_dlst))
// 	{
// 		print("analyze_input : lexer err");
// 		set_exit_status(2);
// 		return (false);
// 	}
// 	if (!parser(token_dlst, cmd_dlst))
// 	{
// 		print("analyze_input : parser err");
// 		set_exit_status(2);
// 		return (false);
// 	}
// 	if (!expansion(cmd_dlst))
// 	{
// 		print("analyze_input : expans err");
// 		return (false);
// 	}
// 	conv_arg(cmd_dlst);
// 	return (true);