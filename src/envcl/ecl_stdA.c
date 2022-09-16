#include "../minishell.h"
#include "envcl.h"
#include "../debug.h"

size_t	ecl_std0(char	*cl);
char	*ecl_std1(char	*cl, size_t	B, size_t i);
char	*ecl_std2(char	*cl, size_t	B, size_t i);
char	*ecl_std3(char	*cl, size_t	B, size_t i);
char	*ecl_std4(char	*cl, size_t	B, size_t i);
char	*ecl_std5(char	*cl, size_t	B, size_t i);
char	*ecl_std6(char	*cl, size_t	B, size_t i);
char	*ecl_std7(char	*cl, size_t	B, size_t i);
char	*ecl_std8(void);

char	*ecl_std(char	*cl, size_t	B)
{
	size_t	i;

	i = ecl_std0(cl);
	if (!cl[i])
		return (ecl_std1(cl, B, i));
	else if (cl[i] == ' ' || cl[i] == '<' || cl[i] == '>' \
	|| cl[i] == '|' || cl[i] == ';' || cl[i] == '&')
		return (ecl_std2(cl, B, i));
	else if (cl[i] == '$')
		return (ecl_std3(cl, B, i));
	else if (cl[i] == '\\')
		return (ecl_std4(cl, B, i));
	else if (cl[i] == '"')
		return (ecl_std5(cl, B, i));
	else if (cl[i] == '\'')
		return (ecl_std6(cl, B, i));
	else if (cl[i] == '(')
		return (ecl_std7(cl, B, i));/* 未完 */
	else //(cl[i] == ')') 構文エラー
		return (ecl_std8());/* 未完 */
	return (NULL);
}

size_t	ecl_std0(char	*cl)
{
	size_t	i;

	i = 0;
	while (cl[i] != ' ' && cl[i] != '<' && cl[i] != '>' \
	&& cl[i] != '|' && cl[i] != ';' && ft_strncmp(cl + i, "&&", 2) \
	&& cl[i] != '$' \
	&& cl[i] != '\\' && cl[i] != '"' && cl[i] != '\'' && cl[i] != '(' && cl[i] != ')' \
	&& cl[i])
		i++;
	return (i);
}

char	*ecl_std1(char	*cl, size_t	B, size_t i)
{
	char	*r;

	r = malloc(B + i + 1);
	if (!r)
		return (m_error());
	r[0] = (char)1;
	r[B + i] = '\0';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*ecl_std2(char *cl, size_t B, size_t i)
{
	char	*r;

	r = ecl_sp(cl + i, B + i + 1);
	if (!r || !*r)
		return (r);
	r[B + i] = ' ';
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*ecl_std3(char *cl, size_t B, size_t i)
{
	char	*r;

	r = ecl_env_std(cl + i, B + i);
	if (!r || !*r)
		return (r);
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}

char	*ecl_std4(char *cl, size_t B, size_t i)
{
	char	*r;

	i += 2;
	r = ecl_std(cl + i, B + i);
	if (!r || !*r)
		return (r);
	if (i)
		ft_memcpy(r + B, cl, i);
	return (r);
}
