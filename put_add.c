/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:14:01 by lsemlali          #+#    #+#             */
/*   Updated: 2021/12/02 16:14:02 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_add(unsigned long nbr, char *base)
{
	unsigned long	k;
	int				count;

	count = 0;
	k = (unsigned long)nbr;
	if (k >= 16)
	{
		count += put_add((k / 16), base);
		put_add((k % 16), base);
	}
	else if (k < 16)
		put_char(base[k]);
	count++;
	return (count);
}
