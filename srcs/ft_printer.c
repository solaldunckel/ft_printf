/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:00:16 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 02:16:25 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char *s, t_printf *tab)
{
	int		len;

	if (s == NULL)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	if (tab->precision && tab->precision_width < len)
		len = tab->precision_width;
	if (tab->width > len && !tab->minus)
		tab->tmp = ft_print_sp(tab->width - len, tab->zero);
	if (tab->precision)
		tab->tmp = ft_strjoin_len(tab->tmp, s, tab->precision_width);
	else
		tab->tmp = ft_strjoin(tab->tmp, s);
	if (tab->width > len && tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	tab->s = ft_strjoin(tab->s, tab->tmp);
}

void	ft_print_nbr(int n, t_printf *tab)
{
	int		len;

	len = ft_intlen(n);
	tab->precision ? tab->zero = 0 : 0;
	if (tab->precision && tab->precision_width > len)
		tab->num = ft_print_sp(tab->precision_width - len, 1);
	tab->num = ft_strjoin(tab->num, ft_itoa(n));
	len = ft_strlen(tab->num);
	(n < 0) ? len++ : 0;
	(n < 0) && tab->zero ? tab->tmp = ft_join_char('-', tab->tmp) : 0;
	if (n == 0 && tab->precision && tab->precision_width == 0 && !tab->width)
		return;
	if (n == 0 && tab->precision && tab->precision_width == 0)
		tab->num = ft_strdup(" ");
	if (tab->width > len && !tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	(n < 0) && !tab->zero ? tab->tmp = ft_join_char('-', tab->tmp) : 0;
	tab->num ? tab->tmp = ft_strjoin(tab->tmp, tab->num) : 0;
	if (tab->width > len && tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	tab->s = ft_strjoin(tab->s, tab->tmp);
}

void	ft_print_nbr_u(unsigned int n, t_printf *tab)
{
	int		len;

	len = ft_uintlen(n);
	tab->precision ? tab->zero = 0 : 0;
	if (tab->precision && tab->precision_width > len)
		tab->num = ft_print_sp(tab->precision_width - len, 1);
	tab->num = ft_strjoin(tab->num, ft_uitoa(n));
	len = ft_strlen(tab->num);
	(n < 0) ? len++ : 0;
	(n < 0) && tab->zero ? tab->tmp = ft_join_char('-', tab->tmp) : 0;
	if (n == 0 && tab->precision && tab->precision_width == 0 && !tab->width)
		return;
	if (n == 0 && tab->precision && tab->precision_width == 0)
		tab->num = ft_strdup(" ");
	if (tab->width > len && !tab->minus)
		tab->tmp = ft_print_sp(tab->width - len, tab->zero);
	(n < 0) && !tab->zero ? tab->tmp = ft_join_char('-', tab->tmp) : 0;
	tab->num ? tab->tmp = ft_strjoin(tab->tmp, tab->num) : 0;
	if (tab->width > len && tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	tab->s = ft_strjoin(tab->s, tab->tmp);
}

void	ft_print_add(long unsigned add, t_printf *tab)
{
	int		len;

	(add == 73896) ? add = 0 : 0;
	len = ft_hexlen(add) + 2;
	if (tab->precision && tab->precision_width > len)
		tab->num = ft_print_sp(tab->precision_width - len + 2, 1);
	tab->num = ft_strjoin(tab->num, ft_itoa_hex(add, "0123456789abcdef"));
	if (tab->width > len && !tab->minus && !tab->zero)
		tab->tmp = ft_print_sp(tab->width - len, tab->zero);
	len = ft_strlen(tab->num) + 2;
	tab->tmp = ft_strjoin(tab->tmp, "0x");
	if (tab->width > len && !tab->minus && tab->zero)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	if (add == 0)
		tab->tmp = tab->tmp = ft_strjoin_len(tab->tmp, tab->num, tab->precision_width);
	else
		tab->tmp = tab->tmp = ft_strjoin(tab->tmp, tab->num);
	if (tab->width > len && tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	tab->s = ft_strjoin(tab->s, tab->tmp);
}

void	ft_print_hex(unsigned int hex, int uppercase, t_printf *tab)
{
	int		len;

	len = ft_hexlen((long unsigned)hex);
	if (hex == 0 && tab->precision && tab->precision_width == 0 && !tab->width)
		return ;
	if (hex == 0 && tab->precision && tab->precision_width == 0)
		tab->num = ft_strdup(" ");
	if (tab->width > len && !tab->minus)
		tab->tmp = ft_print_sp(tab->width - len, tab->zero);
	if (tab->precision_width > len)
	{
		tab->zero = 1;
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->precision_width - len, tab->zero));
		len = tab->width - tab->precision_width;
	}
	tab->zero = 0;
	uppercase ? tab->tmp = ft_strjoin(tab->tmp, ft_itoa_hex(hex, "0123456789ABCDEF")) : 0;
	!uppercase ? tab->tmp = ft_strjoin(tab->tmp, ft_itoa_hex(hex, "0123456789abcdef")) : 0;
	if (tab->width > len && tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	tab->s = ft_strjoin(tab->s, tab->tmp);
}
