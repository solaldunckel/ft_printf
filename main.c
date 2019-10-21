/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:14:34 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 17:04:27 by sdunckel         ###   ########.fr       */
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
	else if (nb == 0)
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

void 	test_c(char *test, char c)
{
	int		ret[2];

	ret[0] = printf(   test, c);
	ret[1] = ft_printf(test, c);
	if (ret[0] == ret[1])
		ft_printf(   "\033[0;32mreturn ✓\033[0m\n");
	else
		ft_printf(   "\033[0;31m=> YOU SHOULD HAVE RETURN %d INSTEAD OF %d !\033[0m\n", ret[0], ret[1]);
	ft_printf("\n");
}

void 	test_str(char *test, char *str)
{
	int		ret[2];

	ret[0] = printf(   test, str);
	ret[1] = ft_printf(test, str);
	if (ret[0] == ret[1])
		ft_printf(   "\033[0;32mreturn ✓\033[0m\n");
	else
		ft_printf(   "\033[0;31m=> YOU SHOULD HAVE RETURN %d INSTEAD OF %d !\033[0m\n", ret[0], ret[1]);
	ft_printf("\n");
}

void 	test_int(char *test, int d)
{
	int		ret[2];

	ret[0] = printf(   test, d);
	ret[1] = ft_printf(test, d);
	if (ret[0] == ret[1])
		ft_printf(   "\033[0;32mreturn ✓\033[0m\n");
	else
		ft_printf(   "\033[0;31m=> YOU SHOULD HAVE RETURN %d INSTEAD OF %d !\033[0m\n", ret[0], ret[1]);
	ft_printf("\n");
}

void 	test_null(char *test)
{
	int		ret[2];

	ret[0] = printf(   test, NULL);
	ret[1] = ft_printf(test, NULL);
	if (ret[0] == ret[1])
		ft_printf(   "\033[0;32mreturn ✓\033[0m\n");
	else
		ft_printf(   "\033[0;31m=> YOU SHOULD HAVE RETURN %d INSTEAD OF %d !\033[0m\n", ret[0], ret[1]);
	ft_printf("\n");
}

int		main(void)
{
	char 	str[] = "slt ma biche";
	int		nb = -2147483646;
	int		i;
	int		ret;
	char 	c;

	i = 0;
	c = 'z';

	//printf = 0.53s user 0.45s system 44% cpu 2.207 total
	//ft_printf = 3.38s user 0.63s system 97% cpu 4.137 total
	// while (i < 1000000)
	// {
	// 	ft_printf("%s lets see if %% works %d ok %p yyy %c\n", str, nb, nb, '0');
	// 	i++;
	// }
	//	ft_printf("why it doesn't work %.2s for god sake %.5s\n", str, str);

	//printf(" => %.10 25p");
	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**************************\n");
	ft_printf("********  RANDOM  ********\n");
	ft_printf("**************************\033[0m\n\n");
	test("helloworld\n", NULL, NULL);
	test("mdr tout marche sauf%32) lalala\n", NULL, NULL);
	test("mdr tout marche sauf%.1) lalala\n", NULL, NULL);
	test("mdr tout marche sauf%-32.) lalala\n", NULL, NULL);
	test_null("si ca marche pas t'es %s\n");
	test_null("si ca marche pas t'es %-32s quand meme\n");
	test_null("si ca marche pas t'es %9s quand meme\n");
	test_null("si ca marche pas t'es %.4s quand meme\n");
	test("      %", NULL, NULL);
	test("", NULL, NULL);
	//
	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();
	// //
	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%s  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test_str("=> %%s : [%s]\n", str);
	test_str("=> %%s : [%.15s]\n", str);
	test_str("=> %%s : [%.5s]\n", str);
	test_str("=> %%s : [%.5 5 .s]\n", str);
	test_str("=> %%s : [%.15 -27s]\n", str);
	test_str("=> %%s : [%.2 -27s]\n", str);
	test_str("=> %%s : [%030s]\n", str);
	//
	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();
	//
	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%d  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test_int("=> %%d : [%d]\n", 42);
	test_int("=> %%d : [%.05d]\n", -42);
	test_int("=> %%d : [%.15d]\n", 42);
	test_int("=> %%d : [%.15-d]\n", 42);
	test_int("=> %%d : [%.-15d]\n", 42);
	test_int("=> %%d : [%015d]\n", 42);
	test_int("=> %%d : [%.1d]\n", 420);
	test_int("=> %%d : [%.12d]\n", -420);
	test_int("=> %%d : [%.15 027d]\n", 420);
	test_int("=> %%d : [%.15-027d]\n", -420);
	test_int("=> %%d : [%.d]\n", 0);
	test_int("=> %%d : [%5.d]\n", 0);
	test_int("=> %%d : [%5.0d]\n", 0);
	test_int("=> %%d : [%20d]\n", INT_MAX);
	test_int("=> %%d : [%20d]\n", INT_MIN);
	//
	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();
	// //
	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%u  ********\n");
	ft_printf("**********************\033[0m\n\n");
	test_int("=> %%u : [%u]\n", 498302);
	test_int("=> %%u : [%.015u]\n", 498302);
	test_int("=> %%u : [%.015-0-27u]\n", 498302);
	test_int("=> %%u : [%20u]\n", 4294967294);
	test_int("=> %%u : [%20u]\n", INT_MIN);
	//
	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();
	//
	printf("\033[2J\n");
	ft_printf("\n\033[0;33m***************************\n");
	ft_printf("********  %%x & %%X  ********\n");
	ft_printf("***************************\033[0m\n\n");
	test("=> %%x : [%x]\n", str, NULL);
	test("=> %%x : [%.15x]\n", str, NULL);
	test("=> %%x : [%020x]\n", str, NULL);
	test("=> %%x : [%-20x]\n", str, NULL);
	test("=> %%x : [%40.2x]\n", str, NULL);
	test("=> %%x : [%.20-40x]\n", str, NULL);
	test("=> %%X : [%12.02X]\n", str, NULL);
	test("=> %%X : [%.2-12X]\n", str, NULL);
	test("=> %%X : [%.2X]\n", str, NULL);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();
	//
	printf("\033[2J\n");
	ft_printf("\n\033[0;33m**********************\n");
	ft_printf("********  %%p  ********\n");
	ft_printf("**********************\033[0m\n\n");
	int 	zer = 120;
	test("=> %%p : [%p]\n", str, NULL);
	test("=> %%p : [%.015p]\n", str, NULL);
	test("=> %%p : [%020p]\n", str, NULL);
	test("=> %%p : [%-20p]\n", str, NULL);
	test("=> %%p : [%10p]\n", str, NULL);
	test("=> %%p : [%40.2p]\n", str, NULL);
	test("=> %%p : [%.40-20p]\n", str, NULL);
	test("=> %%p : [%.25p]\n", str, NULL);
	test("=> %%p : [%.25p]\n", NULL, nb);
	test("=> %%p : [%.10 25p]\n", NULL, 0);
	test("=> %%p : [%.10 -25p]\n", NULL, 0);
	test("=> %%p : [%. 025p]\n", NULL, zer);
	test("=> %%p : [%. 25p]\n", NULL, 0);
	test("=> %%p : [%. 25p]\n", NULL, zer);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();
	// //
	printf("\033[2J\n");
	ft_printf("\033[0;33m*********************\n");
	ft_printf("********  %%  ********\n");
	ft_printf("*********************\033[0m\n\n");
	test("=> %% : {%%}\n", NULL, NULL);
	test("=> %% : {%.020%}\n", NULL, NULL);
	test("=> %% : {%40%}\n", NULL, NULL);
	test("=> %% : {%.0. 040%}\n", NULL, NULL);
	test("=> %% : {%.%}\n", NULL, NULL);
	//test("=> %% : {%%%s%%}\n", str, NULL);

	ft_printf("Appuyer sur une touche pour continuer.");
	getchar();

	printf("\033[2J\n");
	ft_printf("\033[0;33m*********************\n");
	ft_printf("********  %%c  ********\n");
	ft_printf("*********************\033[0m\n\n");
	test_c("=> %%c : {%c}\n", c);
	c = 0;
	test_c("=> %%c : {%c}\n", c);
	test_c("=> %%c : {%2c}\n", c);
	c = 'o';
	test_c("=> %%c : {%.020c}\n", c);
	test_c("=> %%c : {%40c}\n", c);
	test_c("=> %%c : {%.0. 040c}\n", c);
	test_c("=> %%c : {%.c}\n", c);

	return (0);
}
