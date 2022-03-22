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

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "shell_info.h"
#include "error.h"
#include "utils.h"

size_t	get_len(char *s)
{
	char	*ptr;

	ptr = ft_strpbrk(s, "/");
	if (ptr)
		return (ptr - s + 1);
	else
		return (ft_strlen(s));
}

char	*up_dir(char *s)
{
	char	*ptr;

	ptr = ft_strrchr(s + 1, '/');
	if (ptr)
		ptr[0] = '\0';
	else
		s[1] = '\0';
	return (s);
}

char	*path_join(char *s1, char*s2)
{
	char	*joined;

	if (s1[ft_strindexlen(s1)] != '/')
		joined = ft_strjoin(s1, "/");
	else
		joined = ft_strdup(s1);
	if (!joined)
		put_strerror_and_exit();
	join_string(&joined, s2);
	if (!ft_streq(joined, "/") && joined[ft_strindexlen(joined)] == '/')
		joined[ft_strindexlen(joined)] = '\0';
	return (joined);
}

char	*update_path(char *old_path, char *to_join)
{
	char	*new_path;

	if (ft_strneq(to_join, "./", 2) || ft_strneq(to_join, "/", 1))
		return (old_path);
	else if (ft_streq(to_join, "."))
		return (old_path);
	else if (ft_strneq(to_join, "../", 3) || ft_streq(to_join, ".."))
	{
		up_dir(old_path);
		return (old_path);
	}
	else
	{
		new_path = path_join(old_path, to_join);
		free(old_path);
		return (new_path);
	}
}

char	*create_new_cwd_path(char *start, char *dest_path)
{
	size_t	i;
	size_t	len;
	char	*to_join;
	char	*new_cwd;

	i = 0;
	new_cwd = ft_strdup(start);
	if (!new_cwd)
		put_strerror_and_exit();
	while (dest_path[i])
	{
		len = get_len(dest_path + i);
		to_join = ft_strndup(dest_path + i, len);
		if (!to_join)
			put_strerror_and_exit();
		new_cwd = update_path(new_cwd, to_join);
		if (!new_cwd)
			put_strerror_and_exit();
		free(to_join);
		i += len;
	}
	return (new_cwd);
}
