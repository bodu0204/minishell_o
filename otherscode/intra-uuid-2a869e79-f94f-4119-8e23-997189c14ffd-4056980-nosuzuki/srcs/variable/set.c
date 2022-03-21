/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "minishell.h"
#include "variable.h"
#include "error.h"

extern t_msh	g_;

void	var_set_env(void *ctx, char *key, char *value)
{
	if (!hash_add(g_.env, key, value))
		or_exit(NULL, ctx);
}

void	var_set_sp(void *ctx, char *key, char *value)
{
	if (!hash_add(g_.sp_var, key, value))
		or_exit(NULL, ctx);
}

void	var_set_child(void *ctx)
{
	var_set_sp(ctx, "CHILD", NULL);
}
