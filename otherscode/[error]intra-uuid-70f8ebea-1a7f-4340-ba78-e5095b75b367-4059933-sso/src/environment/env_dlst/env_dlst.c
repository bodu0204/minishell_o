/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "environment_variable.h"

#include <stdio.h>
#include "libft.h"

bool	construct_env_dlst(t_dlst **env_dlst, char **envp)
{
	size_t	i;

	*env_dlst = ft_dlstinit();
	if (!*env_dlst)
		return (false);
	i = 0;
	while (envp && envp[i])
	{
		update_env(envp[i]);
		i++;
	}
	set_shlvl();
	return (true);
}

void	destruct_env_dslt(t_dlst **env_dlst)
{
	if (env_dlst == NULL || *env_dlst == NULL)
		return ;
	ft_dlstclear(env_dlst, &destruct_env_tuple);
}
