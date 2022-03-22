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

// #include

#include "libft.h"
#include "token.h"

#define QUOTES "'\""
#define SPACE " "

static size_t	get_enclosed_quote_size(const char *s)
{
	size_t	i;
	char	quote;

	quote = s[0];
	i = 1;
	while (s[i])
	{
		if (s[i] == quote)
			break ;
		i++;
	}
	return (i + 1);
}

static size_t	get_wordsize(char *s, bool in_dquote)
{
	size_t	wordsize;

	if ((s[0] == '\'' || s[0] == '\"' ) && !in_dquote)
		wordsize = get_enclosed_quote_size(s);
	else if (s[0] == '$')
	{
		if (ft_strneq(s, "$?", 2))
			wordsize = 2;
		else
			wordsize = ft_strpbrk_len(s + 1, QUOTES SPACE "$") + 1;
	}
	else
	{
		if (!in_dquote)
			wordsize = ft_strpbrk_len(s, QUOTES "$");
		else
			wordsize = ft_strpbrk_len(s, "$");
	}
	return (wordsize);
}

// TODO : err ck
t_dlst	*decompose_string(char *s, bool in_dquote)
{
	size_t	i;
	size_t	wordsize;
	char	*decomposed;
	t_dlst	*decompos_dlst;

	decompos_dlst = ft_dlstinit();
	if (!decompos_dlst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		wordsize = get_wordsize(s + i, in_dquote);
		decomposed = ft_substr(s, i, wordsize);
		append_tkn_node(decompos_dlst, decomposed);
		i += wordsize;
	}
	return (decompos_dlst);
}
