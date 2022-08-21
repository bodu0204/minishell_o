/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_string.h"
#include "ft_io.h"
#include "hash.h"
#include "builtin.h"
#include "minishell.h"
#include "error.h"
#include "variable.h"
#include "ft_ctype.h"
#include "cache.h"

extern t_msh	g_;

static void	blt_export_set_env(void *ctx, t_exp_var *var)
{
	bool	is_ok;

	is_ok = true;
	if (ft_streq(var->op, "") && !hash_exists(g_.env, var->name))
		is_ok = hash_add(g_.env, var->name, NULL);
	else if (ft_streq(var->op, "="))
		is_ok = hash_add(g_.env, var->name, var->val);
	else if (ft_streq(var->op, "+="))
		is_ok = hash_append_value(g_.env, var->name, var->val);
	if (!is_ok)
	{
		blt_export_free_var(var);
		or_exit(NULL, ctx);
	}
}

bool	blt_export_one(void *ctx, char *arg)
{
	t_exp_var	var;

	blt_export_parse_var(ctx, arg, &var);
	if (!var_is_valid_name(var.name))
	{
		msh_puterrs((char *[]) \
			{ERR_EXPORT_INVAL1, arg, ERR_EXPORT_INVAL2, NULL});
		blt_export_free_var(&var);
		return (false);
	}
	blt_export_set_env(ctx, &var);
	if (ft_streq(var.name, "PATH") && !ft_streq(var.op, ""))
		cache_clear();
	blt_export_free_var(&var);
	return (true);
}

static bool	blt_export_all(void *ctx, size_t argc, char **argv)
{
	bool	is_all_ok;
	size_t	i;

	is_all_ok = true;
	i = 1;
	while (i < argc)
	{
		is_all_ok &= blt_export_one(ctx, argv[i]);
		i++;
	}
	return (is_all_ok);
}

int	blt_export(void *ctx, size_t argc, char **argv)
{
	bool	is_ok;

	if (argc == 1)
	{
		blt_export_print(ctx);
		return (0);
	}
	is_ok = blt_export_all(ctx, argc, argv);
	if (!is_ok)
		return (1);
	return (0);
}
