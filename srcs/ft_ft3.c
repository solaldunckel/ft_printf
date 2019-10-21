/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:23:50 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 01:20:25 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_precision(t_printf *tab)
{
	tab->zero = 0;
	tab->precision = 1;
	tab->precision_parsing = 1;
	tab->precision_width = 0;
}

void	ft_reset_flags(t_printf *tab)
{
	int		i;

	i = 0;
	while (tab->tmp[i])
	{
		tab->tmp[i] = '\0';
		i++;
	}
	i = 0;
	while (tab->num[i])
	{
		tab->num[i] = '\0';
		i++;
	}
	if (!(tab->tmp = malloc(sizeof(char*))))
		return ;
	tab->width = 0;
	tab->precision = 0;
	tab->precision_width = 0;
	tab->precision_parsing = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->offset = 0;
	tab->plus = 0;
	tab->space = 0;
}

size_t	ft_is_flag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

size_t	ft_is_from_pf(char c)
{
	return (ft_is_flag(c) || (c >= '0' && c <= '9')
	|| c == '-' || c == ' ' || c == '.' || c == '+' || c == '*');
}
