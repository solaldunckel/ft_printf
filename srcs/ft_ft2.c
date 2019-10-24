/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:51:05 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/24 15:18:11 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_printf(char *str, int *i)
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

char	*ft_strdup_l(char *s, t_printf *tab)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (tab->precision && tab->precision_width < len)
		len = tab->precision_width;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_c_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	s[1] = '\0';
	return (s);
}

size_t	intlen_printf(intmax_t n)
{
	size_t		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

size_t	uintlen_printf(uintmax_t n)
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
