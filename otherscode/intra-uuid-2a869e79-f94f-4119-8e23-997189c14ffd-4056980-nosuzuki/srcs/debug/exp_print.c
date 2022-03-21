/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "expansion.h"
// #include "ft_list.h"
// #include "color.h"
// #include <stdio.h>
//
// static char	*qtype_to_str(t_etype type)
// {
// 	if (type & E_UNQUOTE)
// 		return ("UNQUOTE");
// 	if (type & E_DQUOTE)
// 		return ("DQUOTE");
// 	if (type & E_SQUOTE)
// 		return ("SQUOTE");
// 	if (type & E_SP)
// 		return ("SP");
// 	return (0);
// }
//
// static char	*vtype_to_str(t_etype type)
// {
// 	if (type & E_VAR)
// 		return ("VAR");
// 	if (type & E_LITERAL)
// 		return ("LITERAL");
// 	if (type & E_SP)
// 		return ("SP");
// 	return (0);
// }
//
// void	exp_print(t_clist *tokens)
// {
// 	t_etok	*token;
//
// 	puts(GREEN"\n==============================="RESET);
// 	puts(GREEN"=========   EXPAND   =========="RESET);
// 	puts(GREEN"===============================\n"RESET);
// 	tokens = tokens->next;
// 	while (!ft_clst_isend(tokens))
// 	{
// 		token = tokens->data;
// 		printf(CYAN"%s %s"RESET" %s -> ", 
// 	qtype_to_str(token->type), vtype_to_str(token->type), token->str);
// 		tokens = tokens->next;
// 	}
// 	puts("");
// }
