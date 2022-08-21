/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "heredoc.h"
#include "ft_list.h"
#include "ft_string.h"
#include "error.h"

#define NEWLINE_LEN 1

static size_t	hdoc_get_total_len(t_clist *lines)
{
	size_t	len;

	len = 0;
	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		len += ft_strlen(lines->data) + NEWLINE_LEN;
		lines = lines->next;
	}
	return (len);
}

char	*hdoc_join_lines(t_hdoc *hdoc, t_clist *lines)
{
	size_t	i;
	size_t	total_len;
	char	*str;

	total_len = hdoc_get_total_len(hdoc->lines);
	str = or_exit(malloc(total_len + 1), hdoc);
	i = 0;
	lines = ft_clstfirst(lines);
	while (!ft_clst_isend(lines))
	{
		i += ft_strlcpy(str + i, lines->data, total_len + 1);
		str[i] = '\n';
		lines = lines->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}
