/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmai      <fmai@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:03:08 by fmai              #+#    #+#             */
/*   Updated: 2022/03/21 23:03:08 by fmai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_environ *env)
{
	char	*cwd_path;
	char	**envp;

	envp = t_environ_to_vector(env);
	cwd_path = get_env_val("PWD", envp);
	if (cwd_path == NULL)
	{
		cwd_path = getcwd(NULL, 1024);
		if (cwd_path == NULL)
		{
			perror("getcwd()");
			return (1);
		}
	}
	printf("%s\n", cwd_path);
	free(cwd_path);
	free_2d_array(envp);
	return (0);
}
