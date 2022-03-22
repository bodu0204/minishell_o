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

#ifndef CMD_H
# define CMD_H

# include "libft.h"

typedef struct s_red {
	bool	is_ambiguous_redirect;
	char	*red_type;
	char	*target_file;
}	t_red;

typedef struct s_cmd {
	char	**argv;
	t_dlst	*arg_token_dlst;
	t_dlst	*redirect_info_dlst;

	int		outfd;
	int		infd;
	int		to_next_infd;

	pid_t	pid;
	int		sig;
	int		exit_status;

	bool	heredoc_is_expand;
	char	*heredoc_str;
	int		heredoc_write_fd;
}	t_cmd;

// cmd.c
bool	construct_cmd_dlst(t_dlst **cmd_dlst);
void	destruct_cmd_dlst(t_dlst **cmd_dlst);
int		get_cmd_exit_status(t_cmd *cmd);
int		get_last_cmd_exit_status(t_dlst *cmd_dlst);
int		get_last_cmd_sig(t_dlst *cmd_dlst);
t_cmd	*construct_cmd(t_dlst *cmd_dlst);
void	destruct_cmd(void *cmd);

// redirect_info
t_red	*construct_red(char *red_type, char *target_file);
void	destruct_red(void *ptr);
void	destruct_red_dlst(t_dlst **red_dlst);
bool	is_ambiguous_redirect(t_red *redirect_info);
char	*get_red_type(t_red *redirect_info);
char	*get_red_target_file(t_red *redirect_info);

void	conv_arg(t_dlst *cmd_dlst);

#endif // CMD_H
