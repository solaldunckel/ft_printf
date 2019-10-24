/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:19 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/24 14:03:55 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_printf(intmax_t n)
{
	char		*str;
	int			num_len;

	num_len = intlen_printf(n);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		if (n < 0)
		{
			str[--num_len] = -(n % 10) + 48;
			n = n / 10;
			n = -n;
		}
		else
		{
			str[--num_len] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (str);
}

char	*uitoa_printf(uintmax_t n)
{
	char		*str;
	int			num_len;

	num_len = uintlen_printf(n);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char	*itoa_base_pf(uintmax_t num, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = intlen_base_pf(num, base);
	base_len = ft_strlen(base);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[num % base_len];
		num = num / base_len;
	}
	return (str);
}
