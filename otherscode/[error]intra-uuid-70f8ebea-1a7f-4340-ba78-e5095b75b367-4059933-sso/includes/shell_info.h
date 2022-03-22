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

#ifndef SHELL_INFO_H
# define SHELL_INFO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>

# include "libft.h"

typedef struct s_shell_info {
	char					*cwd;
	t_dlst					*env_dlst;
	int						interactive;
	int						exit_status;
	volatile sig_atomic_t	sig;
}	t_shell_info;

extern t_shell_info	g_sinfo;

// 
bool	init_shell_info(char **envp);

// interactive
void	set_interactive(bool interactive_status);
bool	is_interactive(void);

// exit_status
void	set_exit_status(int status);
int		get_exit_status(void);

// shell_pwd
void	set_cwd(char *pwd);
char	*get_cwd(void);
void	update_cwd(char *new_pwd);

// sig
void	reset_sig(void);
void	set_sig(int sig);
int		get_sig(void);

#endif // SHELL_INFO_H
