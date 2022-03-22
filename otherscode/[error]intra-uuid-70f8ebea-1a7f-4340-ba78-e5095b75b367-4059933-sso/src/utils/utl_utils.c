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
#include <stdbool.h>
#include "libft.h"
#include "shell_info.h"
#include "environment_variable.h"
#include "utils.h"
#include "error.h"

void	put_exit_msg(void)
{
	if (is_interactive())
		ft_putendl_fd("exit", STDERR_FILENO);
}

void	free_in_loop(char **command, t_dlst *token_dlst, t_dlst *cmd_dlst)
{
	if (get_sig())
	{
		set_exit_status(get_sig() + 128);
		reset_sig();
	}
	ft_free_ptr((void **) command);
	ft_dlstclear_except_sentinel(token_dlst, &free);
	ft_dlstclear_except_sentinel(cmd_dlst, &destruct_cmd);
}

char	*free_and_return(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

void	switch_pipe(int new_fd, int old_fd)
{
	close(old_fd);
	dup2(new_fd, old_fd);
	close(new_fd);
}
