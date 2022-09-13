#include "../minishell.h"
#include "find.h"

int	fi_ok(char *str, char **l)
{
	size_t	i;
	size_t	ii;

	if (l[0][0] != '\0' && ft_strncmp(str, l[0], ft_strlen(l[0])))
		return (0);
	l++;
	if (!l[0])
		return (1);
	while (l[1])
	{
		str = ft_strstr(str, *l);
		if (!str)
			return (0);
		str += ft_strlen(*l);
		l++;
	}
	if (**l == '\0')
		return (1);
	i = ft_strlen(str);
	ii = ft_strlen(*l);
	if (i < ii)
		return (0);
	if (ft_strncmp(str + i - ii, *l, ii))
		return (0);
	return (1);
}
