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
#include <stdbool.h>
#include "libft.h"

bool	is_absolute_path(char *s)
{
	if (s[0] == '/')
		return (true);
	else
		return (false);
}

bool	is_pipe(const char *s)
{
	return (ft_streq(s, "|"));
}

bool	is_redirect(const char *s)
{
	if (ft_streq(s, "<"))
		return (true);
	else if (ft_streq(s, "<<"))
		return (true);
	else if (ft_streq(s, ">"))
		return (true);
	else if (ft_streq(s, ">>"))
		return (true);
	return (false);
}

bool	is_meta_str(const char *s)
{
	return (is_pipe(s) || is_redirect(s));
}

size_t	get_meta_str_size(const char *s)
{
	if (ft_strneq(s, "|", 1))
		return (1);
	else if (ft_strneq(s, "<<", 2))
		return (2);
	else if (ft_strneq(s, "<", 1))
		return (1);
	else if (ft_strneq(s, ">>", 2))
		return (2);
	else if (ft_strneq(s, ">", 1))
		return (1);
	else
		return (0);
}
