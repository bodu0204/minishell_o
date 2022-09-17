/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:15:05 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
