/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bul_pwd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:44:11 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

int	bul_pwd(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	printf("%s\n", get_env("PWD"));
	return (0);
}
