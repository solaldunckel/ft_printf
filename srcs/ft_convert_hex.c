/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:04:08 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/23 15:04:39 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_x(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	str = NULL;
	tab->u = va_arg(ap, unsigned int);
	tab->converter == 'x' ? str = ft_itoa_base(tab->u, "0123456789abcdef") : 0;
	tab->converter == 'X' ? str = ft_itoa_base(tab->u, "0123456789ABCDEF") : 0;
	tab->len = ft_strlen(str);
	str = ft_num_precision(str, tab);
	tab->len = ft_strlen(str);
	if (tab->u == 0 && tab->precision && tab->precision_width == 0
		&& !tab->width)
	{
		free(str);
		return ;
	}
	if (tab->u == 0 && tab->precision && tab->precision_width == 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	if (tab->sharp && tab->u)
		tab->len += 2;
	sp = ft_print_sp(tab);
	ft_join_all(str, sp, tab);
}
