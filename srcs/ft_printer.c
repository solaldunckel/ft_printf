/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:00:16 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/19 01:07:22 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_count(t_printf *tab, int len)
{
	if (tab->width >= len)
		tab->count += tab->width;
	else
		tab->count += len;
}

void	ft_print_spaces(t_printf *tab, int res)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * res + 1)))
		return ;
	while (i < res)
	{
		if (tab->zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
	free(str);
}

void	ft_print_str(const char *s, t_printf *tab)
{
	int		len;

	len = ft_strlen(s);
	if (tab->precision)
		len = tab->precision_width;
	if (tab->width >= len && !tab->minus)
		ft_print_spaces(tab, tab->width - len);
	ft_putstr_p(s, tab);
	if (tab->width >= len && tab->minus)
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
	if (tab->precision)
		off = ft_intlen(n);
	n < 0 ? len++ : 0;
	if (tab->width >= len && !tab->minus)
		ft_print_spaces(tab, tab->width - len - tab->precision_width + off);
	n < 0 ? ft_putchar('-') : 0;
	if (tab->precision)
	{
		tab->zero = 1;
		ft_print_spaces(tab, tab->precision_width - len);
	}
	tab->zero = 0;
	ft_putnbr(n);
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len - tab->precision_width + off);
	if (tab->precision && tab->precision_width > tab->width)
		tab->width = tab->precision_width;
	ft_update_count(tab, len);
}

void	ft_print_percent(char c, t_printf *tab)
{
	int		len;

	len = 1;
	if (tab->width >= len && !tab->minus)
		ft_print_spaces(tab, tab->width - len);
	ft_putchar(c);
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len);
	ft_update_count(tab, len);
}

void	ft_print_add(long unsigned add, t_printf *tab)
{
	int		len;

	len = ft_hexlen(add) + 2;
	if (tab->width >= len && !tab->minus && !tab->zero)
		ft_print_spaces(tab, tab->width - len);
	ft_putstr("0x");
	if (tab->zero && tab->width >= len)
		ft_print_spaces(tab, tab->width - len);
	tab->zero = 0;
	ft_put_hex(add, "0123456789abcdef");
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len);
	ft_update_count(tab, len);
}

void	ft_print_hex(unsigned int hex, int base, t_printf *tab)
{
	int		len;

	len = ft_hexlen((long unsigned)hex);
	if (tab->width >= len && !tab->minus)
		ft_print_spaces(tab, tab->width - len);
	if (base)
		ft_put_hex(hex, "0123456789ABCDEF");
	else
		ft_put_hex(hex, "0123456789abcdef");
	if (tab->width >= len && tab->minus)
		ft_print_spaces(tab, tab->width - len);
	ft_update_count(tab, len);
}
