/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error.h"
#include <stdio.h>
#include <errno.h>
#include <minishell.h>
#include "hash.h"

extern t_msh	g_;

void	msh_del(void *del_target)
{
	t_del	*del;

	del = (t_del *)del_target;
	if (del && del->func)
		del->func(del_target);
}

void	msh_destroy(void *del_target)
{
	msh_del(del_target);
	hash_destroy(&g_.env);
	hash_destroy(&g_.sp_var);
	hash_destroy(&g_.sh_var);
	hash_destroy(&g_.cache);
}

_Noreturn void	exit_after_free(void *del_target, int exit_status)
{
	msh_destroy(del_target);
	exit(exit_status);
}

void	*or_exit(void *allocated, void *del_target)
{
	if (!allocated)
	{
		if (errno)
			perror("minishell");
		exit_after_free(del_target, EXIT_FAILURE);
	}
	return (allocated);
}
