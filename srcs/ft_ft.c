/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:27:19 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 00:44:01 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		num_len;

	num = n;
	num_len = ft_intlen(num);
	if (num < 0)
		num = -num;
	if (!(str = (char*)malloc(sizeof(char) * num_len + 1)))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = num % 10 + 48;
		num = num / 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		num_len;

	num_len = ft_uintlen(n);
	if (!(str = (char*)malloc(sizeof(char) * num_len + 1)))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa_hex(long unsigned num, char *base)
{
	char	*str;
	int		num_len;

	num_len = ft_hexlen(num);
	if (!(str = (char*)malloc(sizeof(char) * num_len + 1)))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[num % 16];
		num = num / 16;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
