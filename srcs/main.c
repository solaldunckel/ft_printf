/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:14:34 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/15 15:54:50 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int argc, char	**argv)
{
	(void)argc;
	(void)argv;
	long			nb = 512512;
	unsigned int	nbu = 4294967295;
	char			c = 'E';
	char 			str[] = "on test tout";
	char			printfff[] = "taille minimum : [%32s]\n";
	printf("\n**** PRINTF ****\n\n");
	printf("%%c : %c\n", c);
	printf("%%s : [%s]\n", str);
	printf("%%p : %p\n", str);
	printf("%%d : %d\n", nb);
	printf("%%i : %i\n", nb);
	printf("%%u : %u\n", nbu);
	printf("%%x : %x\n", nb);
	printf("%%X : %X\n", nb);
	printf("etoile :           [%*s]\n", 19, str);

	printf(printfff, str);
	//printf("taille minimum : [%---25d]\n", nb);

	ft_printf("\n**** FT_PRINTF ****\n\n");
	ft_printf("%%c : %       c\n", c);
	ft_printf("%%s : [%   s]\n", str);
	ft_printf("%%p : %   p\n", str);
	ft_printf("%%d : %  d\n", nb);
	ft_printf("%%i : %i\n", nb);
	ft_printf("%%u : %u\n", nbu);
	ft_printf("%%x : %x\n", nb);
	ft_printf("%%X : %X\n", nb);
	ft_printf("etoile :           [%*s]\n", 19, str);

	ft_printf(printfff, str);
	//ft_printf("taille minimum : [%---25d]\n", nb);

	return (0);
}
