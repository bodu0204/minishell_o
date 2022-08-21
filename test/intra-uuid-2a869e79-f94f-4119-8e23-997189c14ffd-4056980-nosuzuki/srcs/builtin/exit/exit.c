/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_io.h"
#include "error.h"
#include "variable.h"
#include "minishell.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "utils.h"

enum
{
	EX_SUCCESS,
	EX_TOOMANY,
	EX_NOTNUM,
};

extern t_msh	g_;

static void	ex_puterr(int exit_errno, char *numstr)
{
	if (exit_errno == EX_TOOMANY)
		msh_puterr(ERR_EXIT_MANY);
	else if (exit_errno == EX_NOTNUM)
		msh_puterrs((char *[]){"exit: ", numstr, ERR_EXIT_NUM, NULL});
}

static int	ex_get_exit_status(void *ctx, int argc, char *arg, int *exit_errno)
{
	long		num;
	const bool	is_number = util_strtol(ctx, arg, &num);
	const bool	is_no_arg = argc == 1;
	const bool	is_signle_arg = argc == 2;
	const bool	is_success = is_no_arg || (is_number && is_signle_arg);

	if (is_success)
	{
		if (is_no_arg)
			return (var_get_int(g_.sp_var, "?"));
		else
			return (num);
	}
	else
	{
		if (is_number && !is_signle_arg)
			*exit_errno = EX_TOOMANY;
		else if (!is_number)
			*exit_errno = EX_NOTNUM;
		return (2);
	}
}

static bool	is_parent_process(void)
{
	return (!var_sp_exists("CHILD"));
}

int	blt_exit(void *ctx, size_t argc, char **argv)
{
	int	exit_errno;
	int	exit_status;

	if (isatty(STDIN_FILENO) && is_parent_process())
		ft_putendl_fd("exit", STDERR_FILENO);
	exit_errno = EX_SUCCESS;
	exit_status = ex_get_exit_status(ctx, argc, argv[1], &exit_errno);
	if (exit_errno != EX_SUCCESS)
	{
		ex_puterr(exit_errno, argv[1]);
		if (exit_errno == EX_TOOMANY)
			return (1);
	}
	exit_after_free(ctx, exit_status);
}
