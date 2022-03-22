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

#include "shell_info.h"
#include "environment_variable.h"
#include "libft.h"
#include "error.h"

char	*trim_quote(char *s)
{
	char	*trimed;
	size_t	len;

	len = ft_strlen(s) - 2;
	trimed = ft_substr(s, 1, len);
	if (!trimed)
		put_strerror_and_exit();
	return (trimed);
}

char	*join_word_dlst(t_dlst *word_dlst)
{
	char	*tmp;
	char	*joined_string;

	joined_string = ft_strdup("");
	if (!joined_string)
		put_strerror_and_exit();
	word_dlst = word_dlst->next;
	while (word_dlst->content)
	{
		tmp = joined_string;
		joined_string = ft_strjoin(joined_string, word_dlst->content);
		if (!joined_string)
			put_strerror_and_exit();
		free(tmp);
		word_dlst = word_dlst->next;
	}
	return (joined_string);
}

char	*expand_environment_variables(char *s)
{
	char	*expand;

	if (ft_streq(s, "$"))
		expand = ft_strdup("$");
	else if (ft_streq(s, "$?"))
		expand = ft_itoa(get_exit_status());
	else
		expand = ft_getenv(s + 1);
	if (!expand)
		put_strerror_and_exit();
	return (expand);
}

char	*expand_in_dquote(char *s)
{
	char	*tmp;
	char	*expand;
	char	*quote_trimed;
	t_dlst	*decompos_dlst;

	quote_trimed = trim_quote(s);
	decompos_dlst = decompose_string(quote_trimed, true);
	ft_free_ptr((void **)&quote_trimed);
	expand = ft_strdup("");
	decompos_dlst = decompos_dlst->next;
	while (decompos_dlst->content)
	{
		tmp = get_expand_string(decompos_dlst->content, true);
		expand = ft_strjoin_free(expand, tmp);
		decompos_dlst = decompos_dlst->next;
	}
	ft_dlstclear(&decompos_dlst, &free);
	return (expand);
}

char	*get_expand_string(char *to_expand, bool in_dquote)
{
	if (to_expand[0] == '$')
		return (expand_environment_variables(to_expand));
	else if (to_expand[0] == '\'' && !in_dquote)
		return (trim_quote(to_expand));
	else if (to_expand[0] == '"' && !in_dquote)
		return (expand_in_dquote(to_expand));
	else
		return (ft_strdup(to_expand));
}
