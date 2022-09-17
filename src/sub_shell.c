#include "minishell.h"

void	sub_shell(char *cl)
{
	cl = ft_strdup(cl);
	if (!cl)
		return ;
	cl = envcl(cl);
	if (!cl)
		return ;
	cl = asterisk(cl);
	if (!cl)
		return ;
	exe_line(cl);
	free(cl);
	return ;
}
