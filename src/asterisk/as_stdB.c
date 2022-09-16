#include "../minishell.h"
#include "asterisk.h"
#include "../debug.h"

size_t	as_std_aslen1(char *cl, char c);

size_t	as_std_aslen(char *cl)
{
	size_t	i;
	unsigned int	lv;

	lv = 0;
	i = 0;
	if (*cl == '(')
	{
		lv = 1;
		i = 1;
	}
	while ((cl[i] && cl[i] != '*' && cl[i] != ' ') || lv)
	{
		if (cl[i] == '"')
			i += as_std_aslen1(cl, '"');
		else if (cl[i] == '\'')
			i += as_std_aslen1(cl, '\'');
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

size_t	as_std_aslen1(char *cl, char c)
{
	size_t	i;

	i = 1;
	while (cl[i] != c)
		i++;
	return (i + 1);
}
