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

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include "libft.h"
# include "cmd.h"

# define READ	0
# define WRITE	1

// --- exec_execution.c ---
void	execution(t_dlst *cmd_dlst);

// --- exec_multiple_command.c ---
// Executes multiple commands.
int		exec_multiple_command(t_dlst *cmd_dlst);

// --- exec_heredoc.c ---
void	set_heredoc_fd(t_cmd *cmd);
void	write_heredoc(void *ptr);

// --- exec_utils.c ---
// int		get_cmd_exit_status(t_cmd *cmd);
void	dup_fd(t_cmd *cmd);
void	close_fd(t_cmd *cmd);

int		exec_command(char **argv);

int		ft_execvp(char **command);

int		set_redirect(t_cmd	*cmds);

#endif
