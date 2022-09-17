#include "../minishell.h"
#include "asterisk.h"

void	as_std_aslen1(size_t *i, unsigned int *lv, char c);
size_t	as_std_aslen2(char *cl, char c);

size_t	as_std_aslen(char *cl)
{
	size_t			i;
	unsigned int	lv;

	as_std_aslen1(&i, &lv, *cl);
	while ((cl[i] && cl[i] != '*' && cl[i] != ' ') || lv)
	{
		if (cl[i] == '"')
			i += as_std_aslen2(cl, '"');
		else if (cl[i] == '\'')
			i += as_std_aslen2(cl, '\'');
		else if (cl[i] == '\\')
			i += 2;
		else
		{
			if (cl[i] == '(')
				lv++;
			else if (cl[i] == ')')
				lv--;
			i++;
		}
	}
	return (i);
}

void	as_std_aslen1(size_t *i, unsigned int *lv, char c)
{
	*lv = 0;
	*i = 0;
	if (c == '(')
	{
		*lv = 1;
		*i = 1;
	}
	return ;
}

size_t	as_std_aslen2(char *cl, char c)
{
	size_t	i;

	i = 1;
	while (cl[i] != c)
		i++;
	return (i + 1);
}
