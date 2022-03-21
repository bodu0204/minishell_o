/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include <stdbool.h>
# include "error.h"
typedef struct s_exp_var
{
	char	*name;
	char	*op;
	char	*val;
}	t_exp_var;
typedef int	(*t_blt)();
typedef struct s_blt_info
{
	char	*name;
	t_blt	func;
}	t_blt_info;
typedef struct s_cmdtype
{
	char	*cmdpath;
	bool	is_builtin;
}	t_cmdtype;
typedef struct s_paths
{
	char	*newcwd;
	char	*raw_path;
	char	*cdpath_dir;
}	t_paths;
typedef struct s_cd
{
	t_del	del;
	void	*ctx;
	t_paths	paths;
}	t_cd;

bool	blt_export_one(void *ctx, char *arg);
bool	blt_put_cmd_type(void *ctx, char *cmd, char *bltmsg, bool is_type);
bool	retry_cd(t_cd *ctx, t_paths *paths);
bool	try_cd_to_arg(t_cd *ctx, t_paths *paths, char *dir);
bool	try_cd_to_home(t_cd *ctx, t_paths *paths);
bool	try_cd_with_normalize(t_cd *ctx, t_paths *paths, char *raw_path);
char	*create_raw_cmd(void *ctx, char *cmd);
int		blt_cd(void *ctx, int argc, char **argv);
int		blt_echo(void *ctx, size_t argc, char **argv);
int		blt_env(void *ctx, size_t argc, char **argv);
int		blt_exit(void *ctx, size_t argc, char **argv);
int		blt_export(void *ctx, size_t argc, char **argv);
int		blt_hash(void *ctx, size_t argc, char **argv);
int		blt_nop(void *ctx, size_t argc, char **argv);
int		blt_pwd(void *ctx, size_t argc, char **argv);
int		blt_type(void *ctx, size_t argc, char **argv);
int		blt_unset(void *ctx, size_t argc, char **argv);
int		blt_which(void *ctx, size_t argc, char **argv);
void	blt_export_free_var(t_exp_var *var);
void	blt_export_parse_var(void *ctx, char *str, t_exp_var *var);
void	blt_export_print(void *ctx);
void	blt_getopt(char **argv, bool *options, size_t *argvidx, char *optstr);
void	del_paths(t_paths *paths);

#endif
