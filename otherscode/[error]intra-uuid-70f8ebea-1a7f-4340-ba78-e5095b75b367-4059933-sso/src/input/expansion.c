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

// TODO :
void	join_string(char **joined, char *to_join);

void	join_to_end(t_dlst *expanded_dlst, char *to_join)
{
	char	*tmp;

	if (ft_dlst_is_empty(expanded_dlst))
	{
		append_tkn_node(expanded_dlst, ft_strdup(to_join));
	}
	else
	{
		tmp = expanded_dlst->prev->content;
		expanded_dlst->prev->content = ft_strjoin(tmp, to_join);
		if (!expanded_dlst->prev->content)
			put_strerror_and_exit();
		free(tmp);
	}
}

void	tokenize_and_connect(char *expand, t_dlst *expanded_dlst, bool has_next)
{
	t_dlst	*dlst;
	t_dlst	*node;

	if (!expand[ft_strspace_len(expand)])
		return ;
	dlst = tokenize(expand);
	if (dlst == NULL)
		return ;
	else if (ft_dlst_is_empty(dlst))
		;
	else
	{
		node = ft_dlst_eject(dlst->next);
		join_to_end(expanded_dlst, node->content);
		ft_dlstclear(&node, &free);
	}
	ft_dlstconnect(expanded_dlst, dlst);
	ft_dlstclear(&dlst, &free);
	(void)has_next;
	if (has_next && expand[ft_strindexlen(expand)] == ' ')
		append_tkn_node(expanded_dlst, ft_strdup(""));
}

void	wordsplit_expand_str(char *expand, t_dlst *expanded_dlst, bool has_next)
{
	if (expand[ft_strspace_len(expand)] == '\0')
	{
		if (expand[0] == ' ' && !ft_dlst_is_empty(expanded_dlst) && has_next)
			append_tkn_node(expanded_dlst, ft_strdup(""));
		else
			return ;
	}
	else if (expand[0] == ' ')
		if (!ft_dlst_is_empty(expanded_dlst))
			append_tkn_node(expanded_dlst, ft_strdup(""));
	tokenize_and_connect(expand, expanded_dlst, has_next);
}

void	expand_decomposed_string(t_dlst *decompos_dlst, t_dlst *expanded_dlst)
{
	char	*expand;
	char	*joined;

	decompos_dlst = decompos_dlst->next;
	joined = NULL;
	while (decompos_dlst->content)
	{
		expand = get_expand_string(decompos_dlst->content, false);
		if (((char *)decompos_dlst->content)[0] == '$')
			join_string(&joined, expand);
		else
		{
			if (joined)
				wordsplit_expand_str(joined, expanded_dlst, true);
			join_to_end(expanded_dlst, expand);
			free(joined);
			joined = NULL;
		}
		free(expand);
		decompos_dlst = decompos_dlst->next;
	}
	if (joined)
		wordsplit_expand_str(joined, expanded_dlst, false);
	free(joined);
}

// input    : abc$VAR"xyz"
// decompos : abc $VAR "xyz"
// output   : abcHOGExyz
t_dlst	*create_expanded_dlst_from_string(char *s)
{
	t_dlst	*decompos_dlst;
	t_dlst	*expanded_dlst;

	expanded_dlst = ft_dlstinit();
	if (!expanded_dlst)
		put_strerror_and_exit();
	decompos_dlst = decompose_string(s, false);
	expand_decomposed_string(decompos_dlst, expanded_dlst);
	ft_dlstclear(&decompos_dlst, &free);
	return (expanded_dlst);
}
