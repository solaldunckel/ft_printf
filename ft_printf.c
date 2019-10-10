/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:10:11 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/10 18:09:10 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
** c = char
** s = char *
** p = pointeur
** d = int base 10
** i = int detect base (0 = octal / 0x = hexa)
** . = + digits = max de byte print pour une string (0 si pas de digits)
** 0 = zero padding
** - = left adjustement of output
**
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c);
int		ft_parse(int i, const char *str, va_list ap);


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
			while (str[i] == ' ')
				i++;
			if ((i = ft_parse(i, str, ap)) < 0)
				return (-1);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

int		main(int argc, char	**argv)
{
	(void)argc;
	(void)argv;
	long			nb = 2147483650;
	unsigned int	nbu = 4294967295;
	char			c = 'E';
	char 			str[] = " on test tout ";

	printf("\n**** PRINTF ****\n\n");
	printf("%%c : %c\n", c);
	printf("%%s : [%-s]\n", str);
	printf("%%p : %p\n", str);
	printf("%%d : %d\n", nb);
	printf("%%i : %i\n", nb);
	printf("%%u : %u\n", nbu);
	printf("%%x : %x\n", nb);
	printf("%%X : %X\n", nb);

	ft_printf("\n**** FT_PRINTF ****\n\n");
	ft_printf("%%c : %c\n", c);
	ft_printf("%%s : [%s]\n", str);
	ft_printf("%%p : %p\n", str);
	ft_printf("%%d : %d\n", nb);
	ft_printf("%%i : %i\n", nb);
	ft_printf("%%u : %u\n", nbu);
	ft_printf("%%x : %x\n", nb);
	ft_printf("%%X : %X\n", nb);

	return (0);
}
