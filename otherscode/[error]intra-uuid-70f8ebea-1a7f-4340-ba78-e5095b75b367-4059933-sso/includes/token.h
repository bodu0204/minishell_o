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

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"

bool	construct_token_dlst(t_dlst	**token_dlst);
void	destruct_token_dlst(t_dlst **token_dlst);
bool	append_tkn_node(t_dlst *tkn_dlst, char *s);
void	remove_tkn_node(t_dlst *token);
// void	destruct_tkn_dlst_except_sentinel(t_dlst *token_dlst);

char	update_quote_status(char now, char next);
bool	is_quote_closed(const char *s);

t_dlst	*tokenize(const char *s);

#endif
