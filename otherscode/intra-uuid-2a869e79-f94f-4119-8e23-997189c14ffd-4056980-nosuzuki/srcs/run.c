/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "ft_list.h"
#include "execution.h"
#include "color.h"
#include "heredoc.h"
#include "minishell.h"
#include "hash.h"
#include "ft_string.h"
#include "hooks.h"
#include "variable.h"
#include "ft_utils.h"
#include "error.h"
#include "wrapper.h"
#include "run.h"

t_msh	g_;

static bool	parse_input_to_procs(char *input, t_procs **procs)
{
	t_tokens	*tokens;

	*procs = NULL;
	if (lexer(input, &tokens) && parser(input, tokens, procs))
	{
		ft_clst_clear(&tokens, free);
		free(input);
		return (true);
	}
	else
	{
		ft_clst_clear(&tokens, free);
		free(input);
		var_update_exit_status(NULL, 1);
		return (false);
	}
}

static void	run_cmd(char *input)
{
	t_procs		*procs;

	(void)(
		parse_input_to_procs(input, &procs) && \
		heredoc(procs) && \
		execution(procs));
	ft_clst_clear(&procs, msh_del);
}

char	*readline_non_interactive(const char *prompt)
{
	int		fd;
	char	*input;

	fd = ft_dup(STDERR_FILENO);
	close(STDERR_FILENO);
	input = readline(prompt);
	ft_dup2(fd, STDERR_FILENO);
	close(fd);
	return (input);
}

void	msh_run(t_reader readline)
{
	char		*input;
	const char	*prompt = GREEN"minishell"RESET" $ ";

	rl_outstream = stderr;
	while (true)
	{
		g_.line_number++;
		rl_signal_event_hook = hook_rl_reprompt;
		input = readline(prompt);
		if (!input)
			break ;
		if (*input)
			add_history(input);
		run_cmd(input);
	}
}
