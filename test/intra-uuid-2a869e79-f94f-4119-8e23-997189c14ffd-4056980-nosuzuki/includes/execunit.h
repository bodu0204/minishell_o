/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execunit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUNIT_H
# define EXECUNIT_H
# include <stdbool.h>
# include "ft_list.h"
# include "token.h"
# include "error.h"
# include "pipefd.h"
# include "sys/wait.h"

typedef struct s_redir_token
{
	t_token	*fd;
	t_token	*redir_type;
	t_token	*filename;
}	t_redir_token;

typedef enum e_rtype
{
	R_IN = T_REDIR_IN,
	R_OUT = T_REDIR_OUT,
	R_HDOC = T_HDOC,
	R_APP = T_REDIR_APP,
	R_MRG_IN = T_REDIR_MRG_IN,
	R_MRG_OUT = T_REDIR_MRG_OUT,
	R_ERR_OUT = T_REDIR_ERR_OUT,
	R_ERR_APP = T_REDIR_ERR_APP,
	R_ERR_BIT = T_ERR_BIT,
	R_MRG_BIT = T_MRG_BIT,
	R_APP_BIT = T_APP_BIT,
	R_OUT_BIT = T_OUT_BIT,
}	t_rtype;

typedef t_clist			t_cmds;
typedef t_clist			t_redirs;
typedef t_clist			t_procs;
typedef struct s_exec	t_exec;
typedef struct s_proc	t_proc;
typedef int				(*t_executor)();
typedef bool			(*t_launcher)(t_exec *, t_proc *);
struct s_proc
{
	t_del		del;
	size_t		argc;
	union
	{
		char	**argv;
		char	**cmd;
	};
	char		*cmdpath;
	t_cmds		*cmds;
	t_redirs	*redirs;
	t_executor	executor;
	t_launcher	launcher;
	int			builtin_status;
	int			wait_status;
	int			error_status;
	pid_t		pid;
	t_pipefd	pipe;
};

typedef struct s_redir
{
	t_del	del;
	t_rtype	type;
	int		fd;
	char	*hdoc;
	union
	{
		char	*file;
		char	*delim;
	};
}	t_redir;

#endif
