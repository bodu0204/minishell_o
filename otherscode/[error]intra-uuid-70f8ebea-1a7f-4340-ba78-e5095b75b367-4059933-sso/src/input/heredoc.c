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

#include <stdbool.h>
#include <string.h>
#include <errno.h>

#include "input.h"
#include "minishell.h"
#include "shell_info.h"
#include "cmd.h"
#include "libft.h"
#include "error.h"
#include "utils.h"

#include "utl_readline.h"

#define HEREDOC_PROMPT "heredoc> " // zsh

char	*free_and_return(char *s1, char *s2);
char	*trim_quote(char *s);

char	*input_heredoc(char *eof)
{
	char	*line;
	char	*doc_str;

	doc_str = ft_strdup("");
	if (!doc_str)
		put_strerror_and_exit();
	while (true)
	{
		line = wrap_readline(HEREDOC_PROMPT, finish_rl_input, NULL);
		if (get_sig())
			return (free_and_return(line, doc_str));
		if (!line)
		{
			put_err_msg("minish: EOF was sent during the heardock input.");
			return (doc_str);
		}
		if (ft_streq(line, eof))
		{
			free(line);
			return (doc_str);
		}
		join_string(&line, "\n");
		join_string(&doc_str, line);
		free(line);
	}
}

char	*set_eof(t_dlst *redirect_info_dlst, t_cmd *cmd)
{
	char	*eof;

	eof = get_red_target_file(redirect_info_dlst->content);
	if (eof[0] == '\'' || eof[0] == '"')
	{
		eof = trim_quote(eof);
		if (!eof)
			put_strerror_and_exit();
		cmd->heredoc_is_expand = false;
	}
	else
	{
		eof = ft_strdup(eof);
		if (!eof)
			put_strerror_and_exit();
		cmd->heredoc_is_expand = true;
	}
	return (eof);
}

bool	launch_input_heredoc2(t_cmd *cmd, t_dlst *redirect_info_dlst)
{
	char	*eof;

	redirect_info_dlst = redirect_info_dlst->next;
	while (redirect_info_dlst->content)
	{
		if (ft_streq(get_red_type(redirect_info_dlst->content), "<<"))
		{
			ft_free_ptr((void **)&cmd->heredoc_str);
			eof = set_eof(redirect_info_dlst, cmd);
			if (!eof)
				put_strerror_and_exit();
			cmd->heredoc_str = input_heredoc(eof);
			free(eof);
			if (!cmd->heredoc_str)
				return (false);
		}
		redirect_info_dlst = redirect_info_dlst->next;
	}
	return (true);
}

bool	launch_input_heredoc(t_dlst *cmd_dlst)
{
	t_cmd	*cmd;

	cmd_dlst = cmd_dlst->next;
	while (cmd_dlst->content)
	{
		cmd = cmd_dlst->content;
		if (!launch_input_heredoc2(cmd, cmd->redirect_info_dlst))
			return (false);
		cmd_dlst = cmd_dlst->next;
	}
	return (true);
}

// TODO : func name
bool	load_heredoc(t_dlst *cmd_dlst)
{
	if (!is_upper_limit_heardoc(cmd_dlst))
	{
		put_err_msg("minish: maximum here-document count exceeded");
		exit(2);
	}
	if (!launch_input_heredoc(cmd_dlst))
		return (false);
	return (true);
}
