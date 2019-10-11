/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:51:05 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/11 10:57:47 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(long unsigned int num, char *base)
{
	if (num >= 16)
		ft_put_hex(num / 16, base);
	ft_putchar(base[num % 16]);
}

void	ft_put_add(va_list ap)
{
	ft_putstr("0x");
	ft_put_hex(va_arg(ap, long unsigned), "0123456789abcdef");
}

size_t	ft_is_flag(char c)
{
	return (c == ' ' || c == '.' || c == '-' || c == '*' || c == '0');
}

int		ft_check_flag(const char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
	if (ft_is_flag(str[*i]))
		return (str[*i]);
}
