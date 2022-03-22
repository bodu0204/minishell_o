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

#include "cmd.h"

#include <stdio.h>
#include <stdbool.h>
#include "minishell.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "utils.h"

int	redirect(char *target_file)
{
	int	fd;

	fd = wrap_open(target_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		return (-1);
	switch_pipe(fd, 1);
	return (1);
}

int	append(char *target_file)
{
	int	fd;

	fd = wrap_open(target_file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (-1);
	switch_pipe(fd, 1);
	return (1);
}

int	input_redirection(char *target_file)
{
	int	fd;

	fd = wrap_open_twoarg(target_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	switch_pipe(fd, 0);
	return (0);
}

bool	ambiguous_redirect(void)
{
	ft_putendl_fd("ambiguous_redirect", STDERR_FILENO);
	return (false);
}

// TODO : need fd / .
int	set_redirect(t_cmd *cmds)
{
	char	*target_file;
	char	*redirect_type;
	t_dlst	*redirect_info_dlst;

	redirect_info_dlst = cmds->redirect_info_dlst;
	redirect_info_dlst = redirect_info_dlst->next;
	while (redirect_info_dlst->content)
	{
		redirect_type = get_red_type(redirect_info_dlst->content);
		target_file = get_red_target_file(redirect_info_dlst->content);
		if (is_ambiguous_redirect(redirect_info_dlst->content))
			return (ambiguous_redirect());
		if (ft_streq(">", redirect_type))
			if (redirect(target_file) == -1)
				return (false);
		if (ft_streq(">>", redirect_type))
			if (append(target_file) == -1)
				return (false);
		if (ft_streq("<", redirect_type))
			if (input_redirection(target_file) == -1)
				return (false);
		redirect_info_dlst = redirect_info_dlst->next;
	}
	return (-1);
}
