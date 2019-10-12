/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:11 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/12 19:58:08 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i = ft_parse(i, str, ap);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (i);
}

int		main(int argc, char	**argv)
{
	(void)argc;
	(void)argv;
	long			nb = 2147483650;
	unsigned int	nbu = 4294967295;
	char			c = 'E';
	char 			str[] = "on test tout";

	printf("\n**** PRINTF ****\n\n");
	printf("%%c : %c\n", c);
	printf("%%s : [%s]\n", str);
	printf("%%p : %p\n", str);
	printf("%%d : %d\n", nb);
	printf("%%i : %i\n", nb);
	printf("%%u : %u\n", nbu);
	printf("%%x : %x\n", nb);
	printf("%%X : %X\n", nb);

	printf("taille minimum : [%---25 5 s]\n", str);
	printf("taille minimum : [%---25d]\n", nb);

	ft_printf("\n**** FT_PRINTF ****\n\n");
	ft_printf("%%c : %       c\n", c);
	ft_printf("%%s : [%   s]\n", str);
	ft_printf("%%p : %   p\n", str);
	ft_printf("%%d : %  d\n", nb);
	ft_printf("%%i : %i\n", nb);
	ft_printf("%%u : %u\n", nbu);
	ft_printf("%%x : %x\n", nb);
	ft_printf("%%X : %X\n", nb);

	ft_printf("taille minimum : [%----25 s]\n", str);
	ft_printf("taille minimum : [%---25d]\n", nb);

	return (0);
}
