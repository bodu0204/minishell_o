/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_H
# define VARIABLE_H
# include <stdbool.h>
# include "error.h"
typedef struct s_hash	t_hash;
typedef struct s_kvp	t_kvp;
typedef struct s_cwd
{
	t_del	del;
	char	*path;
}	t_cwd;

bool	hash_append_value(t_hash *hash, char *key, char *value);
bool	var_env_exists(char *name);
bool	var_is_valid_name(char *name);
bool	var_sp_exists(char *name);
char	**var_get_all_str(void *ctx, t_hash *hash);
char	*var_get_env(char *name);
char	*var_get_sp(char *name);
int		var_get_int(t_hash *hash, char *key);
t_kvp	**var_get_all_kvp(void *ctx, t_hash *hash);
void	var_init(char *program_name);
void	var_init_cwd(void);
void	var_init_shlvl(void);
void	var_set_child(void *ctx);
void	var_set_env(void *ctx, char *key, char *value);
void	var_set_int(void *ctx, t_hash *hash, char *key, int value);
void	var_set_int_env(void *ctx, char *key, int value);
void	var_set_int_sp(void *ctx, char *key, int value);
void	var_set_sp(void *ctx, char *key, char *value);
void	var_update_exit_status(void	*ctx, int status);
void	var_update_pwd(void);

#endif
