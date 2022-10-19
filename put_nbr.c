/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:14:05 by lsemlali          #+#    #+#             */
/*   Updated: 2021/12/02 16:14:06 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_nbr(int nb, char c)
{
	long int	n;
	int			count;

	count = 0;
	n = nb;
	if (c == 'u')
		n = (unsigned int)n;
	if (n < 0)
	{
		put_char('-');
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += put_nbr(n / 10, c);
		put_char(n % 10 + '0');
	}
	else
	{
		put_char(n + 48);
	}
	count++;
	return (count);
}
