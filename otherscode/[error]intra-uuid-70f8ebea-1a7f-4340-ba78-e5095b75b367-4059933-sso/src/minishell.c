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

#include "minishell.h"
#include "shell_info.h"
#include "input.h"
#include "define.h"
#include "token.h"
#include "cmd.h"
#include "utils.h"
#include "exec.h"
#include "error.h"
#include "utl_readline.h"

void	put_exit_msg(void);
void	free_in_loop(char **command, t_dlst *token_dlst, t_dlst *cmd_dlst);

static void	initialize_loop(t_dlst **token_dlst, t_dlst **cmd_dlst)
{
	if (!construct_token_dlst(token_dlst))
		put_strerror_and_exit();
	if (!construct_cmd_dlst(cmd_dlst))
		put_strerror_and_exit();
	return ;
}

static void	finalize_loop(t_dlst **token_dlst, t_dlst **cmd_dlst)
{
	destruct_token_dlst(token_dlst);
	destruct_cmd_dlst(cmd_dlst);
}

static void	shell_loop(t_dlst *token_dlst, t_dlst *cmd_dlst)
{
	char	*command;

	while (true)
	{
		command = receive_input(BLUE PROMPT RESET);
		if (!command)
			break ;
		if (analyze_input(command, token_dlst, cmd_dlst))
		{
			execution(cmd_dlst);
		}
		free_in_loop(&command, token_dlst, cmd_dlst);
	}
	put_exit_msg();
}

void	minishell(void)
{
	t_dlst	*token_dlst;
	t_dlst	*cmd_dlst;

	initialize_loop(&token_dlst, &cmd_dlst);
	shell_loop(token_dlst, cmd_dlst);
	finalize_loop(&token_dlst, &cmd_dlst);
}
