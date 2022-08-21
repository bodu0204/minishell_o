/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "error.h"
#include "minishell.h"

extern t_msh	g_;

void	hdoc_puterr(char *delim)
{
	char	num[50];

	ft_itoa_buf(g_.line_number, num);
	msh_puterrs((char *[]){
		ERR_HDOC_EOF_1, num, ERR_HDOC_EOF_2, delim, ERR_HDOC_EOF_3, NULL});
}
