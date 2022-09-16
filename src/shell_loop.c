#include "minishell.h"

#include "debug.h"
void	shell_loop(void)
{
	char	*cl;
	int		i;

	cl = getcl();
	while (cl)
	{
		if (*cl)
			add_history(cl);
		cl = envcl(cl);
		if (!cl)
			break ;
TESTs(cl)
 		cl = asterisk(cl);
		if (!cl)
			break ;
TESTs(cl)
		i = exe_line(cl);
		free(cl);
		if (i)
			break ;
		cl = getcl();
	}
	return ;
}
