/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "execunit.h"
# include "pipefd.h"
# include <stdbool.h>
# include <sys/wait.h>
# include "stdfd.h"
# include "builtin.h"
typedef struct s_exec
{
	t_del	del;
	t_procs	*execunits;
	char	**env;
}	t_exec;
enum
{
	FD_STDIN_SAVE = 10,
	FD_STDOUT_SAVE = 11,
	FD_STDERR_SAVE = 12,
	FD_NEXT_PIPE_IN = 13,
};

bool	exec_child(t_exec *ctx, t_proc *proc);
bool	exec_hdoc(t_redir *redir);
bool	exec_is_valid_cmd(char *pathname);
bool	exec_parent(t_exec *ctx, t_proc *proc);
bool	exec_proc(t_exec *ctx, t_proc *proc, bool is_single);
bool	exec_redir(t_proc *proc);
bool	exec_redir_all(t_redirs *redirs);
bool	exec_redir_file(t_redir *redir);
bool	exec_redir_one(t_redir *redir);
bool	exec_set_builtin(t_proc *proc, bool is_single);
bool	exec_set_external(t_exec *ctx, t_proc *proc);
bool	execution(t_procs *execs);
char	*exec_create_cmdpath(t_exec *ctx, t_proc *proc, char *cmd);
char	*exec_find_cmd_from_path(void *ctx, char *cmd, char *envpath);
char	*exec_find_cmd_from_path_hndl_err(t_exec *ctx, t_proc *proc, char *cmd);
int		exec_bltcmp_for_qsort(const void *a, const void *b);
int		exec_external_cmd(t_exec *ctx, size_t argc, char **argv, char *cmdpath);
int		exec_get_shell_exit_status(int raw_status);
int		exec_rtype_to_oflag(t_rtype type);
int		get_pipeline_infd(t_procs *proc);
int		get_pipeline_outfd(t_pipefd *newpipe, t_procs *proc);
pid_t	exec_has_child(t_procs *procs);
t_blt	exec_find_builtin_func(char *name);
t_blt	exec_search_blt_func(char *name, t_blt_info *blts, size_t nmemb);
t_proc	*exec_all_procs(t_exec *ctx, t_procs *procs);
void	exec_all(t_exec *ctx, t_procs *procs);
void	exec_backup_stdfd(void);
void	exec_close_pipe(t_pipefd *fd);
void	exec_connect_pipe(t_pipefd *fd);
void	exec_hndle_invalid_cmd_err(t_proc *proc, char *pathname);
void	exec_init_argv(t_exec *ctx, t_proc *proc);
void	exec_restore_stdfd(void);
void	exec_setup_pipe_connection(t_procs *procs);
void	exec_store_exit_status(t_exec *ctx, t_proc *proc);
void	exec_waitpid_all(t_proc *proc);

#endif
