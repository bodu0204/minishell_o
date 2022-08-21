/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_string.h"
#include "error.h"
#include "utils.h"
#include "variable.h"

#define SHLVL_MAX 999

static int	parse_shlvl(char *shlvl_str)
{
	int		shlvl;
	long	lshlvl;
	bool	is_number;

	is_number = util_strtol(NULL, shlvl_str, &lshlvl);
	if (!is_number)
		shlvl = 0;
	else
		shlvl = (int)lshlvl;
	return (shlvl);
}

static int	update_shlvl(int shlvl)
{
	char	buf[50];

	shlvl++;
	if (shlvl > SHLVL_MAX)
	{
		ft_itoa_buf(shlvl, buf);
		msh_puterrs((char *[]){ERR_SHLVL1, buf, ERR_SHLVL2, NULL});
		shlvl = 1;
	}
	else if (shlvl < 0)
		shlvl = 0;
	return (shlvl);
}

void	var_init_shlvl(void)
{
	char	*shlvl_str;
	int		shlvl_old;
	int		shlvl_new;

	shlvl_str = var_get_env("SHLVL");
	shlvl_old = parse_shlvl(shlvl_str);
	shlvl_new = update_shlvl(shlvl_old);
	var_set_int_env(NULL, "SHLVL", shlvl_new);
}
