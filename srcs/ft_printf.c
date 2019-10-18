/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:11 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 22:10:55 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_it(va_list ap, t_printf *tab, const char *str)
{
	while (str[tab->i])
	{
		if (str[tab->i] == '%')
		{
			tab->i++;
			ft_parse(str, ap, tab);
		}
		else
		{
			tab->count += 1;
			ft_putchar(str[tab->i]);
		}
		tab->i++;
	}
}

int		ft_printf(const char *str, ...)
{
	t_printf	*tab;
	va_list		ap;
	int			count;

	if (!(tab = malloc(sizeof(t_printf))))
		return (0);
	tab->count = 0;
	tab->i = 0;
	va_start(ap, str);
	ft_str_it(ap, tab, str);
	va_end(ap);
	count = tab->count;
	free(tab);
	return (count);
}
