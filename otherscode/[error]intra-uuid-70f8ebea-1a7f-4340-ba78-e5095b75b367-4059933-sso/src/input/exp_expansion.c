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

#include "expansion.h"

#include "token.h"
#include "cmd.h"
#include "utils.h"
#include "libft.h"
#include "error.h"

t_dlst	*create_expanded_dlst_from_string(char *s);

bool	expansion_launch(t_dlst *dlst)
{
	t_dlst	*expanded_dlst;
	t_dlst	*tmp;

	expanded_dlst = ft_dlstinit();
	if (!expanded_dlst)
		put_strerror_and_exit();
	dlst = dlst->next;
	while (dlst->content)
	{
		tmp = create_expanded_dlst_from_string(dlst->content);
		ft_dlstconnect(expanded_dlst, tmp);
		ft_dlstclear(&tmp, &free);
		dlst = dlst->next;
	}
	ft_dlstclear_except_sentinel(dlst, free);
	ft_dlstconnect(dlst, expanded_dlst);
	ft_dlstclear(&expanded_dlst, &free);
	return (true);
}

void	exp_redirect(t_dlst *redirect_info_dlst)
{
	char	*target_file;
	t_red	*red_info;
	t_dlst	*expand_dlst;

	redirect_info_dlst = redirect_info_dlst->next;
	while (redirect_info_dlst->content)
	{
		red_info = redirect_info_dlst->content;
		target_file = get_red_target_file(redirect_info_dlst->content);
		expand_dlst = create_expanded_dlst_from_string(target_file);
		if (ft_dlstsize(expand_dlst) == 1)
		{
			free(target_file);
			red_info->target_file = ft_strdup(expand_dlst->next->content);
		}
		else
		{
			red_info->is_ambiguous_redirect = true;
		}
		ft_dlstclear(&expand_dlst, &free);
		redirect_info_dlst = redirect_info_dlst->next;
	}
}

void	expand_heredoc(t_cmd *cmd)
{
	char	*expand;

	expand = get_expand_string(cmd->heredoc_str, false);
	if (!expand)
		put_strerror_and_exit();
	ft_free_with_set((void **)&cmd->heredoc_str, expand);
	return ;
}

// Parameter Expansion
bool	expansion(t_dlst *cmd_dlst)
{
	t_cmd	*cmd;

	cmd_dlst = cmd_dlst->next;
	while (cmd_dlst->content)
	{
		cmd = cmd_dlst->content;
		expansion_launch(cmd->arg_token_dlst);
		exp_redirect(cmd->redirect_info_dlst);
		if (cmd->heredoc_is_expand)
			expand_heredoc(cmd);
		cmd_dlst = cmd_dlst->next;
	}
	return (true);
}
