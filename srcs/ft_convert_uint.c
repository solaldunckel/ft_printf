/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:03:29 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/23 15:03:43 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_uint(va_list ap, t_printf *tab)
{
	char	*str;
	char	*sp;

	tab->u = va_arg(ap, unsigned int);
	str = ft_uitoa(tab->u);
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
	sp = ft_print_sp(tab);
	ft_join_all(str, sp, tab);
}
