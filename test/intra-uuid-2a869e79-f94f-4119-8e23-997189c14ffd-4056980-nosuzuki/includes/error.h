/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define ERR_MSH			"minishell :"
# define ERR_HDOC_COUNT		"maximum here-document count exceeded"
# define ERR_EXP_AMBIGUOUS	": ambiguous redirect"
# define ERR_LEX_MISS_QUOTE	"missing terminating quote"
# define ERR_PARSE_SYNTAX_1	"syntax error near unexpected token `"
# define ERR_PARSE_SYNTAX_2	"'"
# define ERR_HDOC_EOF_1		"warning: here-document at line "
# define ERR_HDOC_EOF_2		" delimited by end-of-file (wanted `"
# define ERR_HDOC_EOF_3		"')"
# define ERR_SEGV			"Segmentation fault (core dumped)"
# define ERR_EXIT_MANY		"exit: too many arguments"
# define ERR_EXIT_NUM		": numeric argument required"
# define ERR_CMD_NOT_FOUND	": command not found"
# define ERR_EXPORT_INVAL1	"export: `"
# define ERR_EXPORT_INVAL2	"': not a valid identifier"
# define ERR_UNSET_INVAL1	"unset: `"
# define ERR_UNSET_INVAL2	"': not a valid identifier"
# define ERR_SHLVL1			"warning: shell level ("
# define ERR_SHLVL2			") too high, resetting to 1"
# define ERR_CD_NO_HOME		"cd: HOME not set"
# define ERR_CD_TOO_MANY	"cd: too many arguments"
typedef enum e_res
{
	ST_SUCCESS = 0,
	ST_ERR_FORK = 1,
	ST_ERR_EXPAND = 1,
	ST_ERR_DIR = 126,
	ST_ERR_PERMIT = 126,
	ST_ERR_NOT_FOUND = 127,
}	t_res;
typedef struct s_del
{
	void	(*func)();
}	t_del;

_Noreturn void	exit_after_free(void *del_target, int exit_status);
void			*or_exit(void *allocated, void *del_target);
void			msh_del(void *del_target);
void			msh_destroy(void *del_target);
void			msh_put_nocurrent_err(char *name);
void			msh_puterr(char *msg);
void			msh_puterrs(char **msgs);

#endif
