/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:03:37 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/08 16:23:41 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intlen(int n)
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
