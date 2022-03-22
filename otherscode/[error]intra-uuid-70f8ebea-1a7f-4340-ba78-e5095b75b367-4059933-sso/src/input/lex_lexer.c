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

#include "input.h"

#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "shell_info.h"
#include "token.h"
#include "error.h"

bool	lexer(const char *command, t_dlst *token_dlst)
{
	t_dlst	*dlst;

	if (!is_quote_closed(command))
		return (false);
	dlst = tokenize(command);
	if (dlst == NULL)
		put_strerror_and_exit();
	ft_dlstconnect(token_dlst, dlst);
	remove_tkn_node(dlst);
	return (true);
}
