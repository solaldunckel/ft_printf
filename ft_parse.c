/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:00:09 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/10 18:07:52 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	ft_putstr(char *s);
void	ft_putnbr(unsigned long n);
void	ft_putchar(char c);
void	ft_putnbr_u(int n);

void	ft_put_hex(long unsigned int num, char *base)
{
	if (num >= 16)
		ft_put_hex(num / 16, base);
	ft_putchar(base[num % 16]);
}

void	ft_put_add(va_list ap)
{
	ft_putstr("0x");
	ft_put_hex(va_arg(ap, long unsigned), "0123456789abcdef");
}

int		ft_parse(int i, const char *str, va_list ap)
{
	str[i] == 'c' ? ft_putchar(va_arg(ap, int)) : 0;
	str[i] == 's' ? ft_putstr(va_arg(ap, char *)) : 0;
	str[i] == 'p' ? ft_put_add(ap) : 0;
	str[i] == 'd' ? ft_putnbr(va_arg(ap, int)) : 0;
	str[i] == 'i' ? ft_putnbr(va_arg(ap, int)) : 0;
	str[i] == 'u' ? ft_putnbr_u(va_arg(ap, unsigned int)) : 0;
	str[i] == 'x' ? ft_put_hex(va_arg(ap, unsigned int), "0123456789abcdef") : 0;
	str[i] == 'X' ? ft_put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF") : 0;
	str[i] == '%' ? ft_putchar('%') : 0;
	return (i);
}
