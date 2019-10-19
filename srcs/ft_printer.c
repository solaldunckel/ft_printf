/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:00:16 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/19 19:47:52 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char *s, t_printf *tab)
{
	int		len;

	len = ft_strlen(s);
	if (tab->precision)
		len = tab->precision_width;
	if (tab->width > len && !tab->minus)
		ft_print_spaces(tab, tab->width - len);
	ft_putstr_p(s, tab);
	if (tab->width > len && tab->minus)
	{
		if (tab->precision_width < len)
			ft_print_spaces(tab, tab->width - ft_strlen(s));
		else
			ft_print_spaces(tab, tab->width - len);
	}
	if (len > ft_strlen(s))
	{
		ft_update_count(tab, ft_strlen(s));
		return ;
	}
	ft_update_count(tab, len);
}

void	ft_print_nbr(int n, t_printf *tab)
{
	int		len;
	int		off;

	off = 0;
	len = ft_intlen(n);
	n < 0 ? len++ : 0;
	if (tab->width >= len && !tab->minus)
		ft_print_spaces(tab, tab->width - len - tab->precision_width);
	n < 0 ? ft_putchar('-') : 0;
	n < 0 ? tab->precision_width += 1 : 0;
	if (tab->precision)
	{
		tab->zero = 1;
		ft_print_spaces(tab, tab->precision_width - len);
		tab->width += len;
	}
	tab->zero = 0;
	ft_putnbr(n);
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len - tab->precision_width);
	if (tab->precision && tab->precision_width > tab->width)
		tab->width = tab->precision_width;
	else if (tab->precision)
		tab->width -= len;
	ft_update_count(tab, len);
}

void	ft_print_nbr_u(unsigned int n, t_printf *tab)
{
	int		len;
	int		off;

	off = 0;
	len = ft_uintlen(n);
	n < 0 ? len++ : 0;
	if (tab->width >= len && !tab->minus)
		ft_print_spaces(tab, tab->width - len - tab->precision_width);
	n < 0 ? ft_putchar('-') : 0;
	n < 0 ? tab->precision_width += 1 : 0;
	if (tab->precision)
	{
		tab->zero = 1;
		ft_print_spaces(tab, tab->precision_width - len);
		tab->width += len;
	}
	tab->zero = 0;
	ft_putnbr_u(n);
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len - tab->precision_width);
	if (tab->precision && tab->precision_width > tab->width)
		tab->width = tab->precision_width;
	else if (tab->precision)
		tab->width -= len;
	ft_update_count(tab, len);
}

void	ft_print_add(long unsigned add, t_printf *tab)
{
	int		len;
	int		off;

	off = 0;
	len = ft_hexlen(add) + 2;
	if (tab->width > len && !tab->minus && !tab->zero)
		ft_print_spaces(tab, tab->width - len);
	ft_putstr("0x");
	if (tab->width > len && !tab->minus && tab->zero)
		ft_print_spaces(tab, tab->width - len);
	if (tab->precision_width > len)
	{
		tab->zero = 1;
		ft_print_spaces(tab, tab->precision_width - len + 2);
	}
	tab->zero = 0;
	ft_put_hex(add, "0123456789abcdef");
	if (tab->width > len && tab->minus && !(tab->precision_width > len))
		ft_print_spaces(tab, tab->width - len);
	ft_update_count(tab, len);
}

void	ft_print_hex(unsigned int hex, int base, t_printf *tab)
{
	int		len;
	int		off;

	off = 0;
	len = ft_hexlen((long unsigned)hex);
	tab->precision ? tab->zero = 0 : 0;
	if (tab->width > len && !tab->minus)
		ft_print_spaces(tab, tab->width - len);
	tab->precision_width > len ? tab->zero = 1 : 0;
	tab->precision_width > len ? off = tab->precision_width - len : 0;
	if (tab->precision_width > len)
		ft_print_spaces(tab, tab->precision_width - len);
	base ? ft_put_hex(hex, "0123456789ABCDEF") : 0;
	!base ? ft_put_hex(hex, "0123456789abcdef") : 0;
	if (tab->zero && tab->precision_width > tab->width)
		tab->width = tab->precision_width - off;
	else
		tab->width -= off;
	tab->zero = 0;
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len);
	tab->precision_width > tab->width ? tab->width = tab->precision_width : 0;
	tab->precision_width < tab->width ? tab->width += off : 0;
	ft_update_count(tab, len);
}
