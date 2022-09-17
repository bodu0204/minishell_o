/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:48:51 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

t_g	g_;

void	preexe(char **envp);
int		incshlv(void);

int	main(int argc, char *argv[], char *envp[])
{
	(void)argv;
	preexe(envp);
	if (argc == 1)
		shell_loop();
	free_list(ev(NULL));
	return (g_.retn);
}

void	preexe(char **envp)
{
	g_.exeret = 0;
	g_.status = EXEING;
	g_.retn = 0;
	envp = cpy_list(envp);
	if (!envp)
		exit(1);
	ev(envp);
	if (incshlv())
	{
		free_list(ev(NULL));
		exit(1);
	}
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	return ;
}

int	incshlv(void)
{
	int		lv;
	char	lvstr[32];

	lv = ft_atoi(get_env("SHLVL")) + 1;
	itosd(lvstr, lv);
	return (set_env("SHLVL", lvstr));
}
