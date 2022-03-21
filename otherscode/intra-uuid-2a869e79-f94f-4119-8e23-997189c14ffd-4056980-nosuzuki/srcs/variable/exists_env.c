/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exists_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "minishell.h"

extern t_msh	g_;

bool	var_env_exists(char *name)
{
	return (hash_exists(g_.env, name));
}

bool	var_sp_exists(char *name)
{
	return (hash_exists(g_.sp_var, name));
}
