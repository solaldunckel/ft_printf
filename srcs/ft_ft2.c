/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:51:05 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 22:26:09 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(long unsigned num, char *base)
{
	char	*str;
	int		num_len;

	num_len = ft_hexlen(num);
	if (!(str = (char*)malloc(sizeof(char) * num_len + 1)))
		return ;
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[num % 16];
		num = num / 16;
	}
	ft_putstr(str);
	free(str);
}

size_t	ft_is_flag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%');
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
	(*i)--;
	return (atoi);
}
