/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "hash.h"
#include "ft_string.h"

extern t_msh	g_;

void	var_set_int(void *ctx, t_hash *hash, char *key, int value)
{
	char	val_str[50];

	ft_itoa_buf(value, val_str);
	if (hash_add(hash, key, val_str) == false)
		or_exit(NULL, ctx);
}

void	var_set_int_env(void *ctx, char *key, int value)
{
	var_set_int(ctx, g_.env, key, value);
}

void	var_set_int_sp(void *ctx, char *key, int value)
{
	var_set_int(ctx, g_.sp_var, key, value);
}

void	var_update_exit_status(void	*ctx, int status)
{
	var_set_int_sp(ctx, "?", (uint8_t)status);
}
