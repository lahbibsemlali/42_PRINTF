/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:13:52 by lsemlali          #+#    #+#             */
/*   Updated: 2022/10/06 11:24:58 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_cond(char c, va_list v)
{
	int	count;

	count = 0;
	if (c == 's')
		count += put_str(va_arg(v, char *));
	else if (c == 'd' || c == 'i')
		count += put_nbr(va_arg(v, int), c);
	else if (c == 'c')
		count += put_char(va_arg(v, int));
	else if (c == 'u')
		count += put_nbr(va_arg(v, int), c);
	else if (c == 'X')
		count += put_nbr_base(va_arg(v, int), "0123456789ABCDEF");
	else if (c == 'x')
		count += put_nbr_base(va_arg(v, int), "0123456789abcdef");
	else if (c == '%')
		count += put_char('%');
	else if (c == 'p')
	{
		put_char('0');
		put_char('x');
		count += put_add((unsigned long)va_arg(v, void *), "0123456789abcdef");
		count = count + 2;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	v;

	i = 0;
	va_start(v, s);
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_cond(s[i + 1], v);
			i++;
		}
		else
			count += put_char(s[i]);
		i++;
	}
	va_end(v);
	return (count);
}
