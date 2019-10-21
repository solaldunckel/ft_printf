/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:00:09 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 02:31:17 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(const char *str, va_list ap, t_printf *tab)
{
	if (str[tab->i] == '*')
	{
		if (tab->precision_parsing)
			tab->precision_width = va_arg(ap, int);
		else
			tab->width = va_arg(ap, int);
	}
	if (str[tab->i] == '0' && !tab->minus && !tab->precision_parsing)
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
	str[tab->i] == '.' ? ft_set_precision(tab) : 0;
	str[tab->i] == ' ' ? tab->space = 1 : 0;
	str[tab->i] == '+' ? tab->plus = 1 : 0;
}

int		ft_parse2(const char *str, va_list ap, t_printf *tab)
{
	while (!ft_is_flag(str[tab->i]))
	{
		ft_check_flag(str, ap, tab);
		if (str[tab->i + 1] == '\0')
			return (0);
		if (!ft_is_from_pf(str[tab->i + 1]))
		{
			tab->minus ? tab->tmp = ft_join_char(str[tab->i + 1], tab->tmp) : 0;
			tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - 1, tab->zero));
			!tab->minus ? tab->tmp = ft_join_char(str[tab->i + 1], tab->tmp) : 0;
			tab->s = ft_strjoin(tab->s, tab->tmp);
			tab->i++;
			return (0);
		}
		tab->i++;
	}
	return (1);
}

void	ft_parse(const char *str, va_list ap, t_printf *tab)
{
	tab->i++;
	ft_reset_flags(tab);
	if (!ft_parse2(str, ap, tab))
		return ;
	str[tab->i] == 'c' ? ft_print_char(va_arg(ap, int), tab) : 0;
	str[tab->i] == 's' ? ft_print_str(va_arg(ap, char *), tab) : 0;
	str[tab->i] == 'p' ? ft_print_add(va_arg(ap, long unsigned), tab) : 0;
	str[tab->i] == 'd' || str[tab->i] == 'i' ?
		ft_print_nbr(va_arg(ap, int), tab) : 0;
	str[tab->i] == 'u' ? ft_print_nbr_u(va_arg(ap, unsigned int), tab) : 0;
	str[tab->i] == 'x' ? ft_print_hex(va_arg(ap, unsigned int), 0, tab) : 0;
	str[tab->i] == 'X' ? ft_print_hex(va_arg(ap, unsigned int), 1, tab) : 0;
	str[tab->i] == '%' ? ft_print_char('%', tab) : 0;
}
