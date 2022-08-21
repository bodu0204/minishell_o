/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_io.h"
#include "ft_sort.h"
#include "hash.h"
#include "builtin.h"
#include "minishell.h"
#include "variable.h"

extern t_msh	g_;

static int	blt_export_kvpcmp_for_qsort(const void *p1, const void *p2)
{
	const t_kvp	*kvp1 = *(t_kvp **)p1;
	const t_kvp	*kvp2 = *(t_kvp **)p2;

	return (ft_strcmp(kvp1->key, kvp2->key));
}

void	blt_export_print(void *ctx)
{
	t_kvp	**env;
	size_t	i;

	env = var_get_all_kvp(ctx, g_.env);
	ft_qsort(env, g_.env->count, sizeof(t_kvp *), blt_export_kvpcmp_for_qsort);
	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env[i]->key, STDOUT_FILENO);
		if (env[i]->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env[i]->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	free(env);
}
