/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:19 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 16:28:03 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putstr_p(const char *s, t_printf *tab)
{
	if (tab->precision_width > ft_strlen(s))
		tab->precision_width = ft_strlen(s);
	if (tab->precision)
		write(1, s, tab->precision_width);
	else
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	long		nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putchar(n % 10 + 48);
	}
	if (n < 10)
		ft_putchar(n + 48);
}

size_t	ft_intlen(int n)
{
	size_t		len;
	long		num;

	num = n;
	len = 1;
	if (num < 0)
		num = -num;
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

size_t	ft_hexlen(long unsigned n)
{
	size_t		len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
