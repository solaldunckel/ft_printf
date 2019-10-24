/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:35:31 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/09 15:42:44 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intlen_base(int n, char *base)
{
	size_t		len;
	long		base_len;
	long		num;

	num = n;
	len = 1;
	base_len = ft_strlen(base);
	if (num < 0)
		num = -num;
	while (num >= base_len)
	{
		num = num / base_len;
		len++;
	}
	return (len);
}
