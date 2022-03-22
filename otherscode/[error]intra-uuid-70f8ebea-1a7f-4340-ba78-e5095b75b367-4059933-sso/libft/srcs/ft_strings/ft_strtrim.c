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

char	*ft_set_ascii(char *ascii, const char *set)
{
	size_t	i;

	i = 0;
	ft_bzero(ascii, 256);
	while (set[i] != '\0')
	{
		ascii[(unsigned char)set[i]] = '1';
		i++;
	}
	return (ascii);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	char	ascii[256];
	size_t	i;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	ft_set_ascii(ascii, set);
	i = 0;
	while (s1[i] != '\0' && ascii[(unsigned char)s1[i]] == '1')
		i++;
	while (ascii[(unsigned char)s1[len - 1]] == '1' && i < len)
		len--;
	str = ft_substr(s1, i, len - i);
	return (str);
}
