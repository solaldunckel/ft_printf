/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:23:50 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/24 14:03:26 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		intlen_base_pf(uintmax_t n, char *base)
{
	size_t		len;
	long		base_len;
	long		num;

	num = n;
	len = 1;
	base_len = ft_strlen(base);
	while (num >= base_len)
	{
		num = num / base_len;
		len++;
	}
	return (len);
}

size_t	ft_is_flag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'n' || c == 'X' || c == '%');
}

size_t	ft_is_from_pf(char c)
{
	return (ft_is_flag(c) || (c >= '0' && c <= '9')
	|| c == '-' || c == ' ' || c == '.' || c == '+' || c == '#' || c == '*'
	|| c == 'l' || c == 'h');
}

void	ft_set_precision(t_printf *tab)
{
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
	tab->converter = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->sharp = 0;
	tab->len = 0;
	tab->sp_len = 0;
	tab->is_int = 0;
	tab->h_count = 0;
	tab->l_count = 0;
	tab->n = 0;
	tab->u = 0;
}
