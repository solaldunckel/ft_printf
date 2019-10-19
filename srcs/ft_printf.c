/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:11 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/19 11:38:20 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_l(const char *s, int len)
{
	write(1, s, len);
}

void 	ft_str_it(va_list ap, t_printf *tab, const char *str)
{
	char	*s;
	int		j;
	int		pos;

	j = 0;
	pos = 0;
	while (str[tab->i])
	{
		if (str[tab->i] == '%' && tab->i++)
		{
			if (j != 0)
				ft_putstr_l(&str[pos], j);
			ft_parse(str, ap, tab);
			j = 0;
		}
		else
		{
			if (j == 0)
				pos = tab->i;
			tab->count += 1;
			j++;
		}
		tab->i++;
	}
	j ? ft_putstr_l(&str[pos], j) : 0;
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
