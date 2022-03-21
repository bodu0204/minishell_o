/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parser.h"
// #include "execunit.h"
// #include <stdio.h>
// #include "color.h"
//
// char	*type_to_str(t_rtype type)
// {
// 	if (type == R_IN)
// 		return ("R_IN");
// 	if (type == R_OUT)
// 		return ("R_OUT");
// 	if (type == R_HDOC)
// 		return ("R_HDOC");
// 	if (type == R_APP)
// 		return ("R_APP");
// 	if (type == R_MRG_IN)
// 		return ("R_MRG_IN");
// 	if (type == R_MRG_OUT)
// 		return ("R_MRG_OUT");
// 	if (type == R_ERR_OUT)
// 		return ("R_ERR_OUT");
// 	if (type == R_ERR_APP)
// 		return ("R_ERR_APP");
// 	return (NULL);
// }
//
// void	parse_print(t_procs *execs)
// {
// 	t_proc		*eunit;
// 	t_redir		*redir;
// 	t_redirs	*redirs;
// 	t_cmds		*cmds;
//
// 	puts(GREEN"\n==============================="RESET);
// 	puts(GREEN"=========   PARSER   =========="RESET);
// 	puts(GREEN"===============================\n"RESET);
// 	execs = execs->next;
// 	while (!ft_clst_isend(execs))
// 	{
// 		puts("\n===================================");
// 		eunit = execs->data;
// 		cmds = eunit->cmds->next;
// 		while (!ft_clst_isend(cmds))
// 		{
// 			printf("%s ", (char *)cmds->data);
// 			printf(" %s ", "->");
// 			cmds = cmds->next;
// 		}
// 		puts("");
// 		redirs = eunit->redirs->next;
// 		while (!ft_clst_isend(redirs))
// 		{
// 			redir = redirs->data;
// 			printf("%d %s %s", 
// 						redir->fd, type_to_str(redir->type), redir->file);
// 			printf(" %s ", "->");
// 			redirs = redirs->next;
// 		}
// 		execs = execs->next;
// 	}
// 	puts("\n===================================");
// }
//
