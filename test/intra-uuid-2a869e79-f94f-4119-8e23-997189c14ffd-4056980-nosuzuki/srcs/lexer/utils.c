/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "token.h"
#include <stdbool.h>

#define DIGITS_MAX 50

// bool	lex_is_valid_digits_token(t_token *token)
// {
// 	char		digits[DIGITS_MAX + 1];
// 	const char	*start = token->start;
// 	const char	*end = token->start + token->len;
// 	int			unused;
// 	size_t		i;

// 	while (start < end && *start == '0')
// 		start++;
// 	i = 0;
// 	while (i < DIGITS_MAX && start + i < end)
// 	{
// 		digits[i] = start[i];
// 		i++;
// 	}
// 	digits[i] = '\0';
// 	return (!ft_atoi_err(digits, &unused));
// }

bool	lex_is_fd(t_token *now, t_token *next)
{
	return (now && (now->type == T_DIGITS)
		&& next && (next->type & T_REDIR));
}
