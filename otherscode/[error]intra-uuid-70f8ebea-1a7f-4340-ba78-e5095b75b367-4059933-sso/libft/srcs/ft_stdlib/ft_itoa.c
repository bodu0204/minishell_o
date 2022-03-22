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

size_t	count_digit(int	n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	len;
	long	tmp;

	len = count_digit(n);
	num = malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (NULL);
	num[len] = '\0';
	tmp = n;
	if (n < 0)
	{
		num[0] = '-';
		tmp = tmp * -1;
	}
	while (len-- > 0)
	{
		num[len] = (tmp % 10) + '0';
		tmp /= 10;
		if (tmp == 0)
			break ;
	}
	return (num);
}
