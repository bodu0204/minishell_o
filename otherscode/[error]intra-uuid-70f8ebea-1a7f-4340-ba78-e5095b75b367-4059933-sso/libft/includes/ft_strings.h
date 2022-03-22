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

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include "libft.h"

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t lne);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

size_t		ft_strlen(const char *s);
size_t		ft_strindexlen(const char *s);
size_t		ft_strnlen(const char *s, size_t maxlen);
size_t		ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strpbrk(const char *s, const char *charset);
size_t		ft_strpbrk_len(const char *s, const char *charset);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_streq(const char *s1, const char *s2);
int			ft_strcmp(const char *s1, const char *s2);
bool		ft_strneq(const char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_safe_strdup(const char *s1);
// char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_substr(const char *s, size_t start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_safe_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t		ft_strspace_len(const char *s);

size_t		ft_dstrsize(const char **dstr);

#endif
