/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "expansion.h"
#include "ft_utils.h"
#include "ft_string.h"

bool	exp_assign_expanded_file(t_exp *exp, t_clist *files, t_redir *redir)
{
	bool	is_empty;
	char	*filename;

	if (ft_clst_size(files) != 1)
		return (false);
	filename = or_exit(ft_strdup(files->next->data), exp);
	ft_free_assign((void **)&redir->file, filename);
	is_empty = redir->file[0] == '\0';
	return (!is_empty);
}

void	exp_assign_expanded_hdoc(t_exp *exp, t_clist *tokens, t_redir *redir)
{
	char	*hdoc;

	tokens = tokens->next;
	hdoc = exp_join_tokens(exp, &tokens);
	ft_free_assign((void **)&redir->hdoc, hdoc);
}
