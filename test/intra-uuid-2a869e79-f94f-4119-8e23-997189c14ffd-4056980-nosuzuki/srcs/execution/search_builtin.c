/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "builtin.h"
#include "ft_string.h"
#include "ft_sort.h"

int	exec_bltcmp_for_qsort(const void *a, const void *b)
{
	t_blt_info	*blt1;
	t_blt_info	*blt2;

	blt1 = (t_blt_info *)a;
	blt2 = (t_blt_info *)b;
	return (ft_strcmp(blt1->name, blt2->name));
}

t_blt	exec_search_blt_func(char *name, t_blt_info *blts, size_t nmemb)
{
	size_t	low;
	size_t	mid;
	size_t	high;
	int		diff;

	if (!nmemb)
		return (NULL);
	low = 0;
	high = nmemb - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		diff = ft_strcmp(blts[mid].name, name);
		if (diff == 0)
			return (blts[mid].func);
		else if (diff < 0)
			low = mid + 1;
		else if (diff > 0 && mid > 0)
			high = mid - 1;
		else
			return (NULL);
	}
	return (NULL);
}

t_blt	exec_find_builtin_func(char *name)
{
	static t_blt_info	builtins[] = {
		{.name = "cd", .func = blt_cd},
		{.name = "env", .func = blt_env},
		{.name = "pwd", .func = blt_pwd},
		{.name = "echo", .func = blt_echo},
		{.name = "exit", .func = blt_exit},
		{.name = "hash", .func = blt_hash},
		{.name = "type", .func = blt_type},
		{.name = "which", .func = blt_which},
		{.name = "unset", .func = blt_unset},
		{.name = "export", .func = blt_export},
	};
	const size_t		elem_size = sizeof(builtins[0]);
	const size_t		len = sizeof(builtins) / elem_size;
	static bool			is_sorted = false;

	if (!name)
		return (blt_nop);
	if (!is_sorted)
	{
		ft_qsort(builtins, len, elem_size, exec_bltcmp_for_qsort);
		is_sorted = true;
	}
	return (exec_search_blt_func(name, builtins, len));
}
