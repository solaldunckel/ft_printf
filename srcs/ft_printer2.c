/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:25:15 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/19 18:25:46 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
