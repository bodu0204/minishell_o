/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPER_H
# define WRAPPER_H
# include "pipefd.h"
# include <fcntl.h>
# include <stdbool.h>
enum
{
	SYS_OK = 0,
	SYS_ERR = -1,
};

char	*ft_getcwd(void *ctx, char *errplace, char *buf, size_t size);
int		ft_close(int fd);
int		ft_dup(int oldfd);
int		ft_dup2(int oldfd, int newfd);
int		ft_execve(const char *filename, char *const argv[], char *const envp[]);
int		ft_open(const char *pathname, int flags, mode_t mode);
int		ft_pipe(t_pipefd *fd);
pid_t	ft_fork(void);
pid_t	ft_waitpid(pid_t pid, int *raw_status, int options);

#endif
