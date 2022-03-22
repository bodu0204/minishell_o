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

bool	is_ambiguous_redirect(t_red *redirect_info)
{
	return (redirect_info->is_ambiguous_redirect);
}

char	*get_red_type(t_red *redirect_info)
{
	return (redirect_info->red_type);
}

char	*get_red_target_file(t_red *redirect_info)
{
	return (redirect_info->target_file);
}
