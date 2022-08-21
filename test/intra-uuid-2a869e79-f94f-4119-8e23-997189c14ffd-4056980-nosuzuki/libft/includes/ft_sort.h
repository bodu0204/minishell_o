/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H
typedef int	(*t_compare) (const void *, const void *);
typedef struct s_sort
{
	void		*low;
	void		*high;
	void		*mid;
	size_t		size;
	t_compare	cmp;
}	t_sort;

void	ft_msort(int *src, int left, int right, int *tmp);
void	ft_qsort(void *base, size_t nmemb, size_t size, t_compare cmp);

#endif
