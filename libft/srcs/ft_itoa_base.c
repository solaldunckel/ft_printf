/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:31:09 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/09 17:03:35 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char	*str;
	long	num;
	int		neg;
	int		num_len;

	num = n;
	neg = 0;
	num_len = ft_intlen_base(num, base);
	if (num < 0)
	{
		num_len++;
		neg = 1;
		num = -num;
	}
	if (!(str = (char*)malloc(sizeof(char) * 34)))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = num % ft_strlen(base) + 48;
		num = num / ft_strlen(base);
	}
	if (neg)
		str[0] = '-';
	return (str);
}
