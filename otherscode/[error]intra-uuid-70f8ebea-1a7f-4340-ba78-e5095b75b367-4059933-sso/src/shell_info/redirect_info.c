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

#include "cmd.h"

#include <string.h>
#include <errno.h>
#include "libft.h"
#include "error.h"

t_red	*construct_red(char *red_type, char *target_file)
{
	t_red	*redirect_info;

	redirect_info = ft_calloc(1, sizeof(t_red));
	if (!redirect_info)
		put_strerror_and_exit();
	redirect_info->red_type = red_type;
	redirect_info->target_file = target_file;
	return (redirect_info);
}

void	destruct_red(void *ptr)
{
	t_red	*red_info;

	if (!ptr)
		return ;
	red_info = ptr;
	if (red_info->red_type)
		ft_free_ptr((void **)&red_info->red_type);
	if (red_info->target_file)
		ft_free_ptr((void **)&red_info->target_file);
	ft_free_ptr((void **)&ptr);
}

void	destruct_red_dlst(t_dlst **red_dlst)
{
	ft_dlstclear(red_dlst, &destruct_red);
}
