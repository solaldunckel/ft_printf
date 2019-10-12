/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:51:05 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/12 20:16:36 by sdunckel         ###   ########.fr       */
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
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

size_t	ft_is_option(char c)
{
	return (c == '-' || c == '.' || c == '0' || c == '*');
}

int		ft_check_flag(const char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

size_t	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f');
}

int		ft_atoi(const char *str, int *i)
{
	int		atoi;

	atoi = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		atoi = atoi * 10 + str[*i] - 48;
		(*i)++;
	}
	return (atoi);
}
