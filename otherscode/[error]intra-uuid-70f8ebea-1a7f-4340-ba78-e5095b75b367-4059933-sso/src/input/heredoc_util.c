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
#include "cmd.h"

static size_t	count_heredoc(t_dlst *redirect_info_dlst)
{
	size_t	count;

	count = 0;
	redirect_info_dlst = redirect_info_dlst->next;
	while (redirect_info_dlst->content)
	{
		if (ft_streq("<<", get_red_type(redirect_info_dlst->content)))
			count++;
		redirect_info_dlst = redirect_info_dlst->next;
	}
	return (count);
}

bool	is_upper_limit_heardoc(t_dlst *cmd_dlst)
{
	t_cmd	*cmd;
	size_t	count;

	count = 0;
	cmd_dlst = cmd_dlst->next;
	while (cmd_dlst->content)
	{
		cmd = cmd_dlst->content;
		count += count_heredoc(cmd->redirect_info_dlst);
		if (count > HEREDOC_MAX)
		{
			return (false);
		}
		cmd_dlst = cmd_dlst->next;
	}
	return (true);
}
