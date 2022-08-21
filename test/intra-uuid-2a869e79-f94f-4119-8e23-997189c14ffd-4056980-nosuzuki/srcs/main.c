/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <readline/readline.h>
#include <unistd.h>
#include "builtin.h"
#include "signals.h"
#include "variable.h"
#include "cache.h"
#include "run.h"

static void	msh_exit(void)
{
	blt_exit(NULL, 1, (char *[]){"exit", NULL});
}

static void	run_shell(void)
{
	if (isatty(STDIN_FILENO))
		msh_run(readline);
	else if (errno == ENOTTY)
		msh_run(readline_non_interactive);
}

static void	msh_init(char *program_name)
{
	sig_init();
	cache_init();
	var_init(program_name);
}

int	main(int argc, char **argv)
{
	(void)argc;
	msh_init(argv[0]);
	run_shell();
	msh_exit();
}
