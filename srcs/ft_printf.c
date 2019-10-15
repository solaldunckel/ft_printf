/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:11 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/15 14:17:18 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			count;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			i = ft_parse(i, str, ap, &count);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (i);
}
