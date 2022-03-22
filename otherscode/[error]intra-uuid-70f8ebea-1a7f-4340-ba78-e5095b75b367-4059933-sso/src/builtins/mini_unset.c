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

#include "builtins.h"

#include <stdio.h>
#include "environment_variable.h"
#include "error.h"

int	mini_unset(char **argv)
{
	size_t	i;
	size_t	argc;

	argc = ft_dstrsize((const char **)argv);
	if (argc < 1)
		return (EX_FAILURE);
	i = 1;
	while (argv[i])
	{
		ft_unsetenv(argv[i]);
		i++;
	}
	return (EX_SUCCESS);
}
