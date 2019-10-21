/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:25:15 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 02:31:35 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hardjoin(char const *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	return (str);
}

void	ft_print_char(char c, t_printf *tab)
{
	int		len;

	len = 1;
	(!c) ? tab->s = ft_hardjoin(tab->s, c) : 0;
	if (!c)
		tab->offset += 1;
	if (tab->width > len && !tab->minus)
		tab->tmp = ft_print_sp(tab->width - len, tab->zero);
	c ? tab->tmp = ft_join_char(c, tab->tmp) : 0;
	if (tab->width > len && tab->minus)
		tab->tmp = ft_strjoin(tab->tmp, ft_print_sp(tab->width - len, tab->zero));
	tab->s = ft_strjoin(tab->s, tab->tmp);
}

char	*ft_print_sp(int n, int zero)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (i < n)
	{
		if (zero)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
