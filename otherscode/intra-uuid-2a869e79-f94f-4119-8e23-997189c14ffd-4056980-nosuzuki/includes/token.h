/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include <stddef.h>
# include "ft_list.h"

typedef enum e_ttype
{
	T_ERR = 0,
	T_STR = 1 << 0,
	T_FD = 1 << 1,
	T_REDIR = 1 << 2,
	T_PIPE = 1 << 3,
	T_SP = 1 << 4,
	T_NEWLINE = 1 << 25,
	T_ERR_BIT = 1 << 26,
	T_MRG_BIT = 1 << 27,
	T_APP_BIT = 1 << 28,
	T_OUT_BIT = 1 << 29,
	T_NUM_BIT = 1 << 30,
	T_DIGITS = T_STR | T_NUM_BIT,
	T_REDIR_IN = T_REDIR,
	T_REDIR_OUT = T_REDIR | T_OUT_BIT,
	T_HDOC = T_REDIR | T_APP_BIT,
	T_REDIR_APP = T_REDIR | T_OUT_BIT | T_APP_BIT,
	T_REDIR_MRG_IN = T_REDIR | T_MRG_BIT,
	T_REDIR_MRG_OUT = T_REDIR | T_OUT_BIT | T_MRG_BIT,
	T_REDIR_ERR_OUT = T_REDIR | T_OUT_BIT | T_ERR_BIT,
	T_REDIR_ERR_APP = T_REDIR | T_OUT_BIT | T_APP_BIT | T_ERR_BIT,
}	t_ttype;

typedef struct s_token
{
	t_ttype		type;
	const char	*start;
	size_t		len;
}	t_token;

typedef t_clist	t_tokens;

#endif
