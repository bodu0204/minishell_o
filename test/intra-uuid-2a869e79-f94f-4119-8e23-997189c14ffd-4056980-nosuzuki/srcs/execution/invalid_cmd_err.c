/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_cmd_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "execution.h"
#include "wrapper.h"
#include "path.h"

void	exec_hndle_invalid_cmd_err(t_proc *proc, char *pathname)
{
	int	saved_errno;

	saved_errno = errno;
	msh_puterrs((char *[]){pathname, ": ", strerror(errno), NULL});
	if (saved_errno == ENOENT)
		proc->error_status = ST_ERR_NOT_FOUND;
	else
		proc->error_status = ST_ERR_DIR;
}
