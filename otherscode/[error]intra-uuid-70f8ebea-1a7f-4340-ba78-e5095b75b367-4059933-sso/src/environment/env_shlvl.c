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

#include <stdio.h>

#include "environment_variable.h"
#include "libft.h"
#include "utils.h"

#include "define.h"
#include "error.h"

// bash v5.1
// export SHLVL=2147483647   -> 0
// export SHLVL=2147483647a  -> 1
// export SHLVL=2147483646   -> 
// bash: warning: shell level (2147483647) too high, resetting to 1
void	update_shlvl(t_dlst *env_node)
{
	int	now_shlvl;
	int	new_shlvl;

	if (!ft_str_isinteger(get_env_val(env_node->content)))
	{
		ft_putstr_fd("minish: shlvl is invalid, reset to 1", STDERR_FILENO);
		update_env("SHLVL=1");
		return ;
	}
	now_shlvl = ft_atoi(get_env_val(env_node->content));
	if (now_shlvl >= 999)
	{
		ft_putstr_fd("minish: shlvl too high, reset to 1", STDERR_FILENO);
		update_env("SHLVL=1");
	}
	else
	{
		new_shlvl = now_shlvl + 1;
		free(((t_env_tuple *)env_node->content)->val);
		((t_env_tuple *)env_node->content)->val = ft_itoa(new_shlvl);
		if (!((t_env_tuple *)env_node->content)->val)
			put_strerror_and_exit();
	}
}

bool	set_shlvl(void)
{
	t_dlst	*env_node;

	env_node = search_env_node("SHLVL");
	if (env_node)
		update_shlvl(env_node);
	else
		update_env("SHLVL=1");
	return (true);
}
