/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:19 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/15 15:26:10 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *s)
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

void	ft_putstr(char *s, int off)
{
	int		len;
	int		min;

	len = ft_strlen(s);
	min = off + 1;
	if (off > 0)
		while (--min > len)
			ft_putchar(' ');
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
	if (off < 0)
	{
		min = -min + 2;
		while (--min > len)
			ft_putchar(' ');
	}
}

void	ft_putnbr(int n, int off)
{
	long		nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, off);
		ft_putchar(nb % 10 + 48);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_putnbr_u(int n)
{
	unsigned int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

size_t		ft_intlen(int n)
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
