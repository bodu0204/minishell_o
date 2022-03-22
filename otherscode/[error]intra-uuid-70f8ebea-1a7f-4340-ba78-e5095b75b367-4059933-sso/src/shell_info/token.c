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
#include "libft.h"
#include "error.h"

bool	construct_token_dlst(t_dlst	**token_dlst)
{
	*token_dlst = ft_dlstinit();
	if (!*token_dlst)
		return (false);
	return (true);
}

void	destruct_token_dlst(t_dlst **token_dlst)
{
	ft_dlstclear(token_dlst, &free);
}

bool	append_tkn_node(t_dlst *tkn_dlst, char *s)
{
	t_dlst	*tkn_node;

	if (!s)
		put_strerror_and_exit();
	tkn_node = ft_dlstnew(s);
	if (tkn_node == NULL)
		put_strerror_and_exit();
	ft_dlstadd_back(&tkn_dlst, tkn_node);
	return (true);
}

void	remove_tkn_node(t_dlst *token)
{
	if (token == NULL)
		return ;
	token = ft_dlst_eject(token);
	ft_dlstclear(&token, &free);
}

// void	destruct_tkn_dlst_except_sentinel(t_dlst *token_dlst)
// {
// 	t_dlst	*next;

// 	if (token_dlst == NULL || ft_dlst_is_empty(token_dlst))
// 		return ;
// 	next = token_dlst->next;
// 	ft_dlst_eject(token_dlst);
// 	ft_dlstclear(&next, &free);
// }
