/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "builtin.h"
#include "error.h"

static void	set_var(t_exp_var *var, char *str, size_t name_len, size_t op_len)
{
	var->name = ft_substr(str, 0, name_len);
	var->op = ft_substr(str, name_len, op_len);
	var->val = ft_strdup(str + name_len + op_len);
}

void	blt_export_free_var(t_exp_var *var)
{
	free(var->name);
	free(var->op);
	free(var->val);
}

void	blt_export_parse_var(void *ctx, char *str, t_exp_var *var)
{
	const char		*eq_pos = ft_strchr(str, '=');
	const size_t	eq_idx = eq_pos - str;

	if (!eq_pos)
		set_var(var, str, ft_strlen(str), 0);
	else if (eq_idx >= 1 && str[eq_idx - 1] == '+')
		set_var(var, str, eq_idx - 1, 2);
	else
		set_var(var, str, eq_idx, 1);
	if (!var->name || !var->op || !var->val)
	{
		blt_export_free_var(var);
		or_exit(NULL, ctx);
	}
}
