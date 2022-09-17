#include "../minishell.h"
#include "envcl.h"

size_t	ecl_bra1(char	*cl, char c);
char	*ecl_bra2(char	*cl, size_t	B, size_t	i);

char	*ecl_bra(char	*cl, size_t	B)
{
	size_t	i;
	unsigned int	lv;

	i = 1;
	lv = 1;
	while (lv && cl[i])
	{
		if (cl[i] == '\'' || cl[i] == '"')
			i += ecl_bra1(cl + i, cl[i]);
		else if (cl[i] == '\\')
			i += 2;
		else
		{
			if(cl[i] == '(')
				lv++;
			else if(cl[i] == ')')
				lv--;
			i++;
		}
	}
	if (lv)
		return (ft_strdup("") + (printf("syntax error\n") * 0));
	return (ecl_bra2(cl, B, i));
}

size_t	ecl_bra1(char	*cl, char c)
{
	size_t	i;

	if (*cl != c)
		return (0);
	i = 1;
	while (cl[i] != c && cl[i])
		i++;
	return (i + 1);
}

char	*ecl_bra2(char	*cl, size_t	B, size_t	i)
{
	char	*r;
	size_t	ii;

	ii = 0;
	while (cl[i + ii] == ' ')
		ii++;	
	r = ecl_std(cl + i + ii, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = ' ';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}