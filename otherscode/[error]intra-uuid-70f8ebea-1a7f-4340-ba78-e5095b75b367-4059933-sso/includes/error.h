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

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdbool.h>

# define EX_SUCCESS		0
# define EX_FAILURE		1

# define EX_SYNTAX		258

// --- utl_err.c ---
bool	set_error(int num);

void	put_err_msg(char *msg);
void	put_err_msg3(char *s1, char *s2, char *s3);

void	err_exit(char *msg);
void	put_strerror_and_exit(void);

#endif // ERROR_H
