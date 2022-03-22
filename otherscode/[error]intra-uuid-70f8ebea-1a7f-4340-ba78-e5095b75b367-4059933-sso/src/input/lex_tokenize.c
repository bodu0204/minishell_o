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

#include <stdio.h>
#include "token.h"
#include "utils.h"
#include "libft.h"
#include "error.h"

#define NONE 0

char	update_quote_status(char now, char next)
{
	if (now == next)
		return (NONE);
	else if (now == NONE)
		return (next);
	else
		return (now);
}

bool	is_quote_closed(const char *s)
{
	char	quote_status;
	size_t	i;

	i = 0;
	quote_status = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			quote_status = update_quote_status(quote_status, s[i]);
		i++;
	}
	if (quote_status)
		put_err_msg("minish: quotation marks not closed.");
	return (!quote_status);
}

size_t	get_tokensize(const char *s)
{
	size_t	i;
	char	quote_status;

	i = 0;
	quote_status = NONE;
	while (s[i])
	{
		if (quote_status == NONE)
		{
			if (s[i] == ' ')
				return (i);
			else if (get_meta_str_size(s + i))
			{
				if (i == 0)
					return (get_meta_str_size(s));
				else
					return (i);
			}
		}
		if ((s[i] == '\'' || s[i] == '\"'))
			quote_status = update_quote_status(quote_status, s[i]);
		i++;
	}
	return (i);
}

void	divide_to_token_dlst(const char *s, t_dlst *token_dlst)
{
	size_t	i;
	size_t	token_size;

	i = ft_strspace_len(s);
	while (s[i])
	{
		token_size = get_tokensize(s + i);
		append_tkn_node(token_dlst, ft_substr(s, i, token_size));
		i += token_size;
		i += ft_strspace_len(s + i);
	}
}

// echo a " b " ' c ' | cat > f
// -> [echo, a," b ", ' c ', |, cat, >, f]
t_dlst	*tokenize(const char *s)
{
	t_dlst	*token_dlst;

	token_dlst = ft_dlstinit();
	if (token_dlst == NULL)
		return (NULL);
	divide_to_token_dlst(s, token_dlst);
	return (token_dlst);
}
