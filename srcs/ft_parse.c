/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:00:09 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 23:23:32 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(const char *str, va_list ap, t_printf *tab)
{
	while (!ft_is_flag(str[tab->i]))
	{
		if (str[tab->i] == '*')
		{
			if (tab->precision_width)
				tab->width = va_arg(ap, int);
			else
				tab->precision_width = va_arg(ap, int);
		}
		if (str[tab->i] == '0' && !tab->minus)
			tab->zero = 1;
		if (str[tab->i] >= '0' && str[tab->i] <= '9')
		{
			if (tab->precision_parsing)
				tab->precision_width = ft_atoi(str, &tab->i);
			else
				tab->width = ft_atoi(str, &tab->i);
		}
		tab->precision_parsing = 0;
		if (str[tab->i] == '-')
		{
			tab->zero = 0;
			tab->minus = 1;
		}
		if (str[tab->i] == '.')
			ft_set_precision(tab);
		tab->i++;
	}
	return (tab->i);
}

void	ft_set_precision(t_printf *tab)
{
	tab->zero = 0;
	tab->precision = 1;
	tab->precision_parsing = 1;
	tab->precision_width = 0;
}

void	ft_reset_flags(t_printf *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->precision_width = 0;
	tab->precision_parsing = 0;
	tab->minus = 0;
	tab->zero = 0;
}

int		ft_parse(const char *str, va_list ap, t_printf *tab)
{
	ft_reset_flags(tab);
	ft_check_flag(str, ap, tab);
	str[tab->i] == 'c' ? ft_putchar(va_arg(ap, int)) : 0;
	str[tab->i] == 's' ? ft_print_str(va_arg(ap, char *), tab) : 0;
	str[tab->i] == 'p' ? ft_print_add(va_arg(ap, long unsigned), tab) : 0;
	str[tab->i] == 'd' || str[tab->i] == 'i' ?
		ft_print_nbr(va_arg(ap, int), tab) : 0;
	str[tab->i] == 'u' ? ft_putnbr_u(va_arg(ap, unsigned int)) : 0;
	str[tab->i] == 'x' ? ft_print_hex(va_arg(ap, unsigned int), 0, tab) : 0;
	str[tab->i] == 'X' ? ft_print_hex(va_arg(ap, unsigned int), 1, tab) : 0;
	str[tab->i] == '%' ? ft_print_percent('%', tab) : 0;
	return (tab->i);
}
