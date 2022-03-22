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

#include "utils.h"

#include <stdio.h>
#include "libft.h"
#include "error.h"

bool	ft_dlst_is_empty(t_dlst *dlst)
{
	return (!dlst->next->content);
}

void	ft_dlstclear_except_sentinel(t_dlst *dlst, void (*del)(void *))
{
	t_dlst	*next;

	if (dlst == NULL || ft_dlst_is_empty(dlst))
		return ;
	next = dlst->next;
	ft_dlst_eject(dlst);
	ft_dlstclear(&next, (*del));
}

void	join_string(char **joined, char *to_join)
{
	char	*old;
	char	*new;

	if (!*joined)
	{
		old = ft_strdup("");
		if (!old)
			put_strerror_and_exit();
	}
	else
		old = *joined;
	new = ft_strjoin(old, to_join);
	if (!new)
		put_strerror_and_exit();
	free(old);
	*joined = new;
	return ;
}
