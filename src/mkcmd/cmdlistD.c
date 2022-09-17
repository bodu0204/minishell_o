#include "../minishell.h"
#include "mkcmd.h"

char	**cmdlist0(t_cmd *c, char *cl, char **ncl, size_t ll)
{
	char	**r;
	char	*s;

	s = tk_std(cl, 0);
	cl = skip_tk(cl);
	if (!s)
		return (NULL);
	r = cmdlist(c, cl, ncl, ll + 1);
	if (!r || !*r)
	{
		free(s);
		return (r);
	}
	r[ll] = s;
	return (r);
}
