/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:11 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 17:16:10 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_it(va_list ap, t_printf *tab, const char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	while (str[tab->i] != '\0')
	{
		if (str[tab->i] == '%')
		{
			if (str[tab->i] == '%' && str[tab->i + 1] == '\0')
				break ;
			(i != 0) ? tab->s = ft_strjoin(tab->s, s) : 0;
			(i != 0) ? i = 0 : 0;
			ft_parse(str, ap, tab);
		}
		else
		{
			s[i++] = str[tab->i];
			s[i] = '\0';
		}
		tab->i++;
	}
	(i != 0) ? tab->s = ft_strjoin(tab->s, s) : 0;
}

int		ft_printf(const char *str, ...)
{
	t_printf	*tab;
	va_list		ap;
	int			count;

	if (!(tab = malloc(sizeof(t_printf))))
		return (0);
	if (!(tab->s = malloc(sizeof(char*))))
		return (0);
	if (!(tab->tmp = malloc(sizeof(char*))))
		return (0);
	if (!(tab->num = malloc(sizeof(char*))))
		return (0);
	tab->i = 0;
	va_start(ap, str);
	ft_str_it(ap, tab, str);
	va_end(ap);
	count = ft_strlen(tab->s) + tab->offset;
	ft_putstr_len(tab->s, count);
	free(tab->s);
	free(tab);
	return (count);
}
