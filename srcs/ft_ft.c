/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:19 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/19 10:48:22 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(const char *s, t_printf *tab)
{
	if (tab->precision_width > ft_strlen(s))
		tab->precision_width = ft_strlen(s);
	if (tab->precision)
		write(1, s, tab->precision_width);
	else
		ft_putstr(s);
}

void	ft_putnbr(int n)
{
	char	*str;
	int		num_len;

	num_len = ft_intlen(n);
	if (n == -2147483648)
	{
		ft_putstr("2147483648");
		return ;
	}
	if (n < 0)
		n = -n;
	if (!(str = malloc(sizeof(char) * num_len + 1)))
		return ;
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + 48;
		n = n / 10;
	}
	ft_putstr(str);
	free(str);
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putchar(n % 10 + 48);
	}
	if (n < 10)
		ft_putchar(n + 48);
}
