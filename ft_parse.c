/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:00:09 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/12 20:16:56 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse(int i, const char *str, va_list ap)
{
	int		off;
	int		tr;

	off = 0;
	while (!ft_is_flag(str[i]))
	{
		if (str[i] == '*')
			off = va_arg(ap, int);
		if (str[i] == '.')
			tr = ft_atoi(str, &i);
		i++;
	}
	str[i] == 'c' ? ft_putchar(va_arg(ap, int)) : 0;
	str[i] == 's' ? ft_putstr(va_arg(ap, char *)) : 0;
	str[i] == 'p' ? ft_put_add(ap) : 0;
	str[i] == 'd' || str[i] == 'i' ? ft_putnbr(va_arg(ap, int)) : 0;
	str[i] == 'u' ? ft_putnbr_u(va_arg(ap, unsigned int)) : 0;
	str[i] == 'x' ? ft_put_hex(va_arg(ap, unsigned int), "0123456789abcdef") : 0;
	str[i] == 'X' ? ft_put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF") : 0;
	str[i] == '%' ? ft_putchar('%') : 0;
	return (i);
}
