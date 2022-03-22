/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear(char **p, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(p[j]);
		p[j] = NULL;
		j++;
	}
	free(p);
	return (NULL);
}

static size_t	count_c(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (j);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	return (j);
}

static size_t	count_next_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*set_val(char *pi, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s)
	{
		pi[i] = *s;
		s++;
		i++;
	}
	pi[i] = '\0';
	return (pi);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = count_c(s, c);
	p = (char **)malloc(sizeof(char *) * (j + 1));
	if (p == NULL)
		return (NULL);
	while (i < j)
	{
		while (*s == c)
			s++;
		p[i] = (char *)malloc(sizeof(char) * (count_next_c(s, c) + 1));
		if (p[i] == NULL)
			return (clear(p, i));
		p[i] = set_val(p[i], s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	p[j] = NULL;
	return (p);
}
