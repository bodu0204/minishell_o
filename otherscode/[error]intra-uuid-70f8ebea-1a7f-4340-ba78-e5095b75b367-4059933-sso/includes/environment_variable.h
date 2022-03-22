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

#ifndef ENVIRONMENT_VARIABLE_H
# define ENVIRONMENT_VARIABLE_H

# include <stdbool.h>
# include "libft.h"

typedef struct s_env_tuple {
	char	*key;
	char	*val;
}	t_env_tuple;

bool			construct_env_dlst(t_dlst **env_dlst, char **envp);
void			destruct_env_dslt(t_dlst **env_dlst);

t_env_tuple		*construct_env_tuple(char *key, char *val);
void			destruct_env_tuple(void *ptr);
bool			insert_to_env_dlst(t_dlst *env_node);
t_dlst			*search_env_node(char *key);

t_dlst			*get_env_dlst(void);
char			*get_env_key(t_env_tuple *env);
char			*get_env_val(t_env_tuple *env);

bool			has_env(char *key);
bool			ft_setenv(char *key, char *val);
bool			update_env(char *str);
char			*ft_getenv(char *key);
void			ft_unsetenv(char *key);

bool			set_shlvl(void);

bool			has_key_and_val(char *str);
size_t			get_env_key_size(char *env);
char			*extract_key(char *str);
bool			separate_environment_variables_for_key_and_val(char *str);
bool			set_only_key_as_environment_variable(char *str);

#endif // ENVIRONMENT_VARIABLE_H
