/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:19 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 22:12:25 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(const char *s, t_printf *tab)
{
	if (tab->precision_width > ft_strlen(s))
		tab->precision_width = ft_strlen(s);
	if (tab->precision)
		write(1, s, tab->precision_width);
	else
		ft_putstr(s);
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
