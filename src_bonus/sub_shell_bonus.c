/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_shell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:49:08 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	sub_shell(char *cl)
{
	cl = ft_strdup(cl);
	if (!cl)
		return ;
	cl = envcl(cl);
	if (!cl)
		return ;
	cl = asterisk(cl);
	if (!cl)
		return ;
	exe_line(cl);
	free(cl);
	return ;
}
