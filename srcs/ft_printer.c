/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:00:16 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/17 18:09:36 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char *s, t_printf *tab)
{
	int		len;

	len = ft_strlen(s);
	if (ABS(tab->width) >= len)
		tab->count += len + ABS(tab->width);
	else
		tab->count += len;
	ft_putstr(s);
}

void	ft_print_nbr(int n, t_printf *tab)
{
	int		len;

	len = ft_intlen(n);
	if (ABS(tab->width) >= len)
		tab->count += ABS(tab->width);
	else
		tab->count += len;
	if (n < 0)
		len++;
	ft_putnbr(n);
}

void	ft_print_percent(char c, t_printf *tab)
{
	int		len;

	len = 1;
	if (ABS(tab->width) >= len)
		tab->count += ABS(tab->width);
	else
		tab->count += len;
	ft_putchar(c);
}

void	ft_print_add(long unsigned add, t_printf *tab)
{
	int		len;

	len = ft_hexlen(add) + 2;
	if (ABS(tab->width) >= len)
		tab->count += ABS(tab->width);
	else
		tab->count += len;
	ft_put_add(add);
}

void	ft_print_hex(unsigned int hex, int base, t_printf *tab)
{
	int		len;

	len = ft_hexlen((long unsigned)hex);
	if (ABS(tab->width) >= len)
		tab->count += ABS(tab->width);
	else
		tab->count += len;
	if (base)
		ft_put_hex(hex, "0123456789ABCDEF");
	else
		ft_put_hex(hex, "0123456789abcdef");
}
