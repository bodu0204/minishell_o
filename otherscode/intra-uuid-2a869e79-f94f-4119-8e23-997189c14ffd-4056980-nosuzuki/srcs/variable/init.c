/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "minishell.h"
#include <stdlib.h>
#include "ft_string.h"
#include "error.h"
#include "variable.h"
#include "builtin.h"
#include "utils.h"

extern t_msh	g_;

static void	var_new(void)
{
	g_.env = hash_new(1);
	g_.sh_var = hash_new(1);
	g_.sp_var = hash_new(1);
	if (!g_.env || !g_.sh_var || !g_.sp_var)
		or_exit(NULL, NULL);
}

static void	var_init_sp(char *program_name)
{
	var_update_exit_status(NULL, 0);
	var_set_sp(NULL, "0", program_name);
}

static void	var_import_env(void)
{
	size_t		i;
	extern char	**environ;

	i = 0;
	while (environ[i])
	{
		blt_export_one(NULL, environ[i]);
		i++;
	}
}

static void	var_init_env(void)
{
	var_import_env();
	var_init_shlvl();
}

void	var_init(char *program_name)
{
	var_new();
	var_init_sp(program_name);
	var_init_env();
	var_init_cwd();
	var_update_pwd();
}
