/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:14:34 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/19 11:43:50 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void 	test(char *test, char *str, int nb)
{
	int		ret[2];

	if (str)
	{
		ret[0] = printf(   test, str);
		ret[1] = ft_printf(test, str);
	}
	else if (nb)
	{
		ret[0] = printf(   test, nb);
		ret[1] = ft_printf(test, nb);
	}
	else if (nb && str)
	{
		ret[0] = printf(   test, nb, str);
		ret[1] = ft_printf(test, nb, str);
	}
	else
	{
		ret[0] = printf(   test);
		ret[1] = ft_printf(test);
	}
	if (ret[0] == ret[1])
		ft_printf(   "\033[0;32mreturn ✓\033[0m\n");
	else
		ft_printf(   "\033[0;31m=> YOU SHOULD HAVE RETURN %d INSTEAD OF %d !\033[0m\n", ret[0], ret[1]);
	ft_printf("\n");
}

int		main(void)
{
	char 	str[] = "slt ma biche";

	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**************************\n");
	ft_printf("********  RANDOM  ********\n");
	ft_printf("**************************\033[0m\n\n");
	test("helloworld\n", NULL, NULL);
	test("mdr tout marche sauf%32) lalala\n", NULL, NULL);
	test("mdr tout marche sauf%-32.) lalala\n", NULL, NULL);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%s  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test("=> %%s : [%s]\n", str, NULL);
	test("=> %%s : [%.15s]\n", str, NULL);
	test("=> %%s : [%.5s]\n", str, NULL);
	test("=> %%s : [%.5 5 .s]\n", str, NULL);
	test("=> %%s : [%.15 -27s]\n", str, NULL);
	test("=> %%s : [%.2 -27s]\n", str, NULL);
	test("=> %%s : [%20s]\n", str, NULL);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%d  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test("=> %%d : [%d]\n", NULL, 42);
	test("=> %%d : [%.015d]\n", NULL, 42);
	test("=> %%d : [%.015-027d]\n", NULL, 42);
	test("=> %%d : [%20d]\n", NULL, INT_MAX);
	test("=> %%d : [%20d]\n", NULL, INT_MIN);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%u  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test("=> %%u : [%u]\n", NULL, 498302);
	test("=> %%u : [%.015u]\n", NULL, 498302);
	test("=> %%u : [%.015-027u]\n", NULL, 498302);
	test("=> %%u : [%20u]\n", NULL, UINT_MAX);
	test("=> %%u : [%20u]\n", NULL, INT_MIN);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%x & %%X  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test("=> %%x : [%x]\n", str, NULL);
	test("=> %%x : [%.15x]\n", str, NULL);
	test("=> %%x : [%020x]\n", str, NULL);
	test("=> %%x : [%-20x]\n", str, NULL);
	test("=> %%x : [%40.2x]\n", str, NULL);
	test("=> %%x : [%.20-40x]\n", str, NULL);
	test("=> %%X : [%12.02X]\n", str, NULL);
	test("=> %%X : [%.2-12X]\n", str, NULL);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%p  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test("=> %%p : [%p]\n", str, NULL);
	test("=> %%p : [%.015p]\n", str, NULL);
	test("=> %%p : [%020p]\n", str, NULL);
	test("=> %%p : [%-20p]\n", str, NULL);
	test("=> %%p : [%10p]\n", str, NULL);
	test("=> %%p : [%40.2p]\n", str, NULL);
	test("=> %%p : [%.20-40p]\n", str, NULL);
	test("=> %%p : [%.40-20p]\n", str, NULL);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\033[0;33m*********************\n");
	ft_printf("********  %%  ********\n");
	ft_printf("*********************\033[0m\n\n");
	test("=> %% : {%%}\n", NULL, NULL);
	test("=> %% : {%.020%}\n", NULL, NULL);
	test("=> %% : {%40%}\n", NULL, NULL);
	test("=> %% : {%.0. 040%}\n", NULL, NULL);
	test("=> %% : {%.%}\n", NULL, NULL);
	test("=> %% : {%%%s%%}\n", str, NULL);

	return (0);
}
