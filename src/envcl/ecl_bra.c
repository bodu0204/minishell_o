#include "../minishell.h"
#include "envcl.h"
#include "../debug.h"

char	*ecl_bra(char	*cl, size_t	B)
{
	size_t	i;
	unsigned int	lv;
	char	*r;

	i = 1;
	lv = 1;
	while (lv && cl[i])
	{
		if (cl[i] == '\'')
		{
			i++;
			while (cl[i] != '\'' && cl[i])
				i++;
		}
		else if (cl[i] == '"')
		{
			i++;
			while (cl[i] != '"' && cl[i])
				i++;
		}
		else if (cl[i] == '\\')
			i ++;
		if (cl[i])
		{
			if(cl[i] == '(')
				lv++;
			else if(cl[i] == ')')
				lv--;
			i++;
		}
	}
	if (lv)
	{
		printf("syntax error\n");
		return (ft_strdup(""));
	}
	size_t	ii = 0;
	while (cl[i + ii] == ' ')
		ii++;	
	r = ecl_std(cl + i, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = ' ';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
