/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include <stdbool.h>
typedef struct s_clist	t_clist;
typedef bool			(*t_exist)(const char *);

bool	path_dir_exists(const char *pathname);
bool	path_file_exists(const char *pathname);
char	*get_current_dir(void *ctx);
char	*path_create_absolute(void *ctx, char *pathname);
char	*path_join_with_normalize(char *cwd, char *pathname);
t_clist	*path_find_files_from_path(void *ctx, char *name, char *paths);

#endif
