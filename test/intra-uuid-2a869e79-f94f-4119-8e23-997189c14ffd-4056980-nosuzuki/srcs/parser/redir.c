/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_string.h"
#include "execunit.h"
#include "token.h"
#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

t_rtype	parse_ttype_to_rtype(t_ttype type)
{
	if (type == T_REDIR_IN)
		return (R_IN);
	if (type == T_REDIR_OUT)
		return (R_OUT);
	if (type == T_HDOC)
		return (R_HDOC);
	if (type == T_REDIR_APP)
		return (R_APP);
	if (type == T_REDIR_MRG_IN)
		return (R_MRG_IN);
	if (type == T_REDIR_MRG_OUT)
		return (R_MRG_OUT);
	if (type == T_REDIR_ERR_OUT)
		return (R_ERR_OUT);
	if (type == T_REDIR_ERR_APP)
		return (R_ERR_APP);
	return (0);
}

char	*parse_get_token_str(t_parse *ctx, t_token *token)
{
	return (or_exit(ft_substr(token->start, 0, token->len), ctx));
}

int	parse_fd(t_parse *ctx, t_token	*fd_token, t_ttype redir_type)
{
	int		fd;
	char	*fdstr;

	if (fd_token)
	{
		fdstr = parse_get_token_str(ctx, fd_token);
		fd = ft_atoi(fdstr);
		free(fdstr);
	}
	else if (redir_type & T_OUT_BIT)
		fd = STDOUT_FILENO;
	else
		fd = STDIN_FILENO;
	return (fd);
}
