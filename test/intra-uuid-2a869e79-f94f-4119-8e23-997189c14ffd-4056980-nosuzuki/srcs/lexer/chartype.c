/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdbool.h>

bool	lex_isspace(char c)
{
	return (c && ft_strchr(" \t", c));
}

bool	lex_isop(char c)
{
	return (c && ft_strchr("<>|", c));
}

bool	lex_isquote(char c)
{
	return (c && ft_strchr("\'\"", c));
}

bool	lex_isspecial(char c)
{
	return (lex_isspace(c) || lex_isop(c));
}
