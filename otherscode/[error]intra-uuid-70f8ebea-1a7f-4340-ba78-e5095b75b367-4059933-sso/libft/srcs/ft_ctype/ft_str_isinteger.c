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

bool	ft_str_isinteger(char *str)
{
	size_t			i;
	int				sign;
	unsigned long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] - 44) * -1;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (sign == 1 && num > INT_MAX)
			return (false);
		if (sign == -1 && num > (long)INT_MIN * -1)
			return (false);
		i++;
	}
	if (i != 0 && str[i] == '\0' && ft_isdigit(str[i - 1]))
		return (true);
	return (false);
}
