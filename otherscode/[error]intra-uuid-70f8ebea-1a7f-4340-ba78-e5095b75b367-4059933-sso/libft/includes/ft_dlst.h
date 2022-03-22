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

#ifndef FT_DLST_H
# define FT_DLST_H

# include "libft.h"

typedef struct s_dlst
{
	void			*content;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}				t_dlst;

void		ft_dlst_link(t_dlst *front, t_dlst *back);
void		ft_dlst_insert(t_dlst *dlst, t_dlst *new);
void		ft_dlstconnect(t_dlst *dest, t_dlst *src);
t_dlst		*ft_dlst_eject(t_dlst *dlst);

t_dlst		*ft_dlstinit(void);
t_dlst		*ft_dlstnew(void *content);
void		ft_dlstadd_front(t_dlst **dlst, t_dlst *new);
void		ft_dlstadd_back(t_dlst **dlst, t_dlst *new);
int			ft_dlstsize(t_dlst *dlst);
void		ft_dlstdelone(t_dlst *dlst, void (*del)(void *));
void		ft_dlstclear(t_dlst **dlst, void (*del)(void *));
void		ft_dlstiter(t_dlst *dlst, void (*f)(void *));
void		**ft_dlst_to_dptr(t_dlst **dlst);

#endif
