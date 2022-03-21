/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <readline/readline.h>
#include "heredoc.h"
#include "expansion.h"
#include "ft_list.h"
#include "ft_utils.h"
#include "error.h"
#include "ft_string.h"
#include "minishell.h"

extern t_msh	g_;

static char	*hdoc_get_formatted_delimiter(t_hdoc *hdoc, char *delim)
{
	char	*new_delim;
	t_etoks	*tokens;

	hdoc->tokens = or_exit(ft_clstnew(NULL), hdoc);
	tokens = hdoc->tokens;
	exp_tokenize_quote(hdoc, delim, tokens);
	exp_tokenize_var(hdoc, tokens);
	tokens = tokens->next;
	new_delim = exp_join_tokens(hdoc, &tokens);
	ft_clst_clear(&hdoc->tokens, msh_del);
	return (new_delim);
}

void	hdoc_format_delimiter(t_hdoc *hdoc, t_redir *redir)
{
	char	*delim;

	delim = hdoc_get_formatted_delimiter(hdoc, redir->delim);
	ft_free_assign((void **)&redir->delim, delim);
}

static void	hdoc_add_lines(t_hdoc *hdoc, t_clist *lines, char *line)
{
	or_exit(ft_clstnew_add_back(lines, line), hdoc);
}

static bool	is_delim(char *input, char *delim)
{
	return (ft_streq(input, delim));
}

bool	hdoc_input_lines(t_hdoc *hdoc, char *delim)
{
	g_.signum = 0;
	while (true)
	{
		hdoc->input = readline("> ");
		if (g_.signum)
		{
			ft_free_assign((void **)&hdoc->input, NULL);
			return (false);
		}
		if (!hdoc->input)
		{
			hdoc_puterr(delim);
			break ;
		}
		if (is_delim(hdoc->input, delim))
		{
			ft_free_assign((void **)&hdoc->input, NULL);
			break ;
		}
		hdoc_add_lines(hdoc, hdoc->lines, hdoc->input);
	}
	return (true);
}
