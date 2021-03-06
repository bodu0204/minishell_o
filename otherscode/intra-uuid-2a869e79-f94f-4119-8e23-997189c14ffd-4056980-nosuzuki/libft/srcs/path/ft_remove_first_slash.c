/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_first_slash.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_remove_first_char(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		str[0] = str[1];
		str++;
	}
}

void	ft_remove_first_slash(char *str)
{
	ft_remove_first_char(str);
}
