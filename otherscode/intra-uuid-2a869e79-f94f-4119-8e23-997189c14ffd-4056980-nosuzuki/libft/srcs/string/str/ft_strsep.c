/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdbool.h>

bool	get_next_token(char **strptr, char *delims, char **token)
{
	*token = ft_strsep(strptr, delims);
	return (*token != NULL);
}

static bool	ft_is_delim(char c, char *delims)
{
	while (*delims)
	{
		if (*delims == c)
			return (true);
		delims++;
	}
	return (false);
}

char	*ft_strsep(char **strptr, char *delims)
{
	char	*token;

	if (!*strptr)
		return (NULL);
	token = *strptr;
	while (**strptr && !ft_is_delim(**strptr, delims))
		(*strptr)++;
	if (**strptr)
	{
		**strptr = '\0';
		(*strptr)++;
	}
	else
		*strptr = NULL;
	return (token);
}
