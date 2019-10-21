/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:36:00 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 16:32:35 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_len(const char *s, int count)
{
	write(1, s, count);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

size_t	ft_intlen(int n)
{
	size_t		len;
	long		num;

	num = n;
	len = 1;
	if (num < 0)
		num = -num;
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

size_t	ft_uintlen(unsigned int n)
{
	size_t		len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

size_t	ft_hexlen(long unsigned n)
{
	size_t		len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
