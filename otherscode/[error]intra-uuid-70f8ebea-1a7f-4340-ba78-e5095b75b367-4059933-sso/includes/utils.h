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

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "cmd.h"
# include "libft.h"

// --- utl_metastr.c ---
bool	is_absolute_path(char *s);
bool	is_pipe(const char *s);
bool	is_redirect(const char *s);
bool	is_meta_str(const char *s);
size_t	get_meta_str_size(const char *s);

bool	is_builtin(char	*command);
int		exec_builtin(char **command);

void	join_string(char **joined, char *to_join);
void	switch_pipe(int new_fd, int old_fd);

char	**get_environ(void);

// --- dlst utils ---
bool	ft_dlst_is_empty(t_dlst *dlst);
void	ft_dlstclear_except_sentinel(t_dlst *dlst, void (*del)(void *));

// --- path utils ---
char	*up_dir(char *s);
size_t	number_of_characters_to_next_path(char *s);
char	*create_new_cwd_path(char *start, char *dest_path);

// --- wrapped syscall---
int		wrap_open(const char *path, int oflag, mode_t mode);
int		wrap_open_twoarg(const char *path, int oflag);
bool	wrap_close(int fd);
bool	wrap_pipe(int *pipe_in, int *pipe_out);
int		wrap_dup2(int oldfd, int newfd);
pid_t	wrap_fork(void);

#endif
