/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:14:03 by lsemlali          #+#    #+#             */
/*   Updated: 2021/12/02 16:14:04 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_nbr_base(int nbr, char *base)
{
	long int	k;
	int			count;

	count = 0;
	k = (unsigned int)nbr;
	if (k >= 16)
	{
		count += put_nbr_base((k / 16), base);
		put_nbr_base((k % 16), base);
	}
	else if (k < 16)
		put_char(base[k]);
	count++;
	return (count);
}
