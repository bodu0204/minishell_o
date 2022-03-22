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

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] - 44) * -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if ((ret == (__LONG_MAX__ / 10) && str[i] > '7') \
		 || ret > (__LONG_LONG_MAX__ / 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(sign * ret));
}
