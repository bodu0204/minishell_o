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

#include "shell_info.h"
#include "environment_variable.h"
#include "utils.h"

t_dlst	*get_env_dlst(void)
{
	return (g_sinfo.env_dlst);
}

t_dlst	*search_env_node(char *key)
{
	char	*to_cmp_key;
	t_dlst	*env_dlst;

	env_dlst = get_env_dlst();
	env_dlst = env_dlst->next;
	while (env_dlst->content)
	{
		to_cmp_key = get_env_key(env_dlst->content);
		if (ft_streq(key, to_cmp_key))
			return (env_dlst);
		env_dlst = env_dlst->next;
	}
	return (NULL);
}

void	overwrite_environment_variable(t_dlst *env_dlst, t_dlst *env_node)
{
	t_dlst		*ejected;
	t_env_tuple	*env;

	env = env_node->content;
	if (env->val == NULL)
	{
		destruct_env_dslt(&env_node);
		return ;
	}
	ft_dlstadd_back(&env_dlst, env_node);
	ejected = ft_dlst_eject(env_dlst);
	destruct_env_dslt(&ejected);
}

bool	insert_to_env_dlst(t_dlst *env_node)
{
	char	*key;
	char	*to_cmp_key;
	t_dlst	*env_dlst;

	env_dlst = get_env_dlst();
	key = get_env_key(env_node->content);
	env_dlst = env_dlst->next;
	while (env_dlst->content)
	{
		to_cmp_key = get_env_key(env_dlst->content);
		if (ft_streq(key, to_cmp_key))
		{
			overwrite_environment_variable(env_dlst, env_node);
			return (true);
		}
		if (ft_strcmp(key, to_cmp_key) < 0)
			break ;
		env_dlst = env_dlst->next;
	}
	ft_dlstadd_back(&env_dlst, env_node);
	return (true);
}
