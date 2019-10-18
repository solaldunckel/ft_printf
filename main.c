/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:14:34 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 16:40:02 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int	ret[2];
	char	*str = "astek";
	char	stre[] = {'a', 's', 10, 'e', 'k', 0};

	// (void)argc;
	// (void)argv;
	// long			nb = 512512;
	// unsigned int	nbu = 4294967295;
	// char			c = 'E';
	// char 			str[] = "on test tout";
	// char			printfff[] = "taille minimum : [%32s]\n";
	// printf("\n**** PRINTF ****\n\n");
	// printf("%%c : %c\n", c);
	// printf("%%s : [%s]\n", str);
	// printf("%%p : %p\n", str);
	// printf("%%d : %d\n", nb);
	// printf("%%i : %i\n", nb);
	// printf("%%u : %u\n", nbu);
	// printf("%%x : %x\n", nb);
	// printf("%%X : %X\n", nb);
	// printf("etoile :           [%*s]\n", 19, str);
	//
	// printf(printfff, str);
	// //printf("taille minimum : [%---25d]\n", nb);
	//
	// ft_printf("\n**** FT_PRINTF ****\n\n");
	// ft_printf("%%c : %       c\n", c);
	// ft_printf("%%s : [%   s]\n", str);
	// ft_printf("%%p : %   p\n", str);
	// ft_printf("%%d : %  d\n", nb);
	// ft_printf("%%i : %i\n", nb);
	// ft_printf("%%u : %u\n", nbu);
	// ft_printf("%%x : %x\n", nb);
	// ft_printf("%%X : %X\n", nb);
	// ft_printf("etoile :           [%*s]\n", 19, str);
	//
	// ft_printf(printfff, str);
	//ft_printf("taille minimum : [%---25d]\n", nb);
	//
	// printf("##### Tests simple : 1 point par test reussi #####\n");
	// printf(   "0) Modulo [%%] : {%%}\n");
	// ft_printf("=> Modulo [%%] : {%%}\n");
	// printf(   "1) Nombre signe [d] : {%d}\n", 42);
	// ft_printf("=> Nombre signe [d] : {%d}\n", 42);
	// printf(   "2) Nombre signe [i] : {%i}\n", 42);
	// ft_printf("=> Nombre signe [i] : {%i}\n", 42);
	// printf(   "4) Nombre non signe [u] : {%u}\n", 42);
	// ft_printf("=> Nombre non signe [u] : {%u}\n", 42);
	// printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
	// ft_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
	// printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
	// ft_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
	// printf(   "8) Caractere [c] : {%c}\n", 42);
	// ft_printf("=> Caractere [c] : {%c}\n", 42);
	// printf(   "9) Chaine [s] : {%s}\n", str);
	// ft_printf("=> Chaine [s] : {%s}\n", str);
	// printf(   "11) Pointeur [p] : {%p}\n", str);
	// ft_printf("=>  Pointeur [p] : {%p}\n", str);
	//
	// printf("Appuyez sur [entree] pour continuer...\n");
	// getchar();
	//
	// printf("\n##### Tests pour verifier : -1pt par resultat errone #####\n");
	// printf(   "1) Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
	// ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
	// printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
	// ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
	// printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
	// ft_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
	// printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
	// ft_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
	// printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
	// ft_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
	// printf("Appuyez sur une touche pour continuer...\n");
	// getchar();

	printf("\n##### Formatage : 1pt pour 3 tests reussis  #####\n");
	// printf(   "4) Formatage simple [0d] : {%0d}\n", 42);
	// ft_printf("=> Formatage simple [0d] : {%0d}\n", 42);
	// printf(   "5) Formatage simple [5d] : {%5d}\n", 42);
	// ft_printf("=> Formatage simple [5d] : {%5d}\n", 42);
	// printf(   "6) Formatage simple [ d] : {% d}\n", 42);
	// ft_printf("=> Formatage simple [ d] : {% d}\n", 42);
	printf(   "7) Formatage simple [-d] : {%d}\n", -422);
	ft_printf("=> Formatage simple [-d] : {%d}\n", -422);
	// printf(   "8) Formatage simple [+d] : {%+d}\n", 42);
	// ft_printf("=> Formatage simple [+d] : {%+d}\n", 42);
	// printf(   "9) Formatage simple [+d] : {%+d}\n", -42);
	// ft_printf("=> Formatage simple [+d] : {%+d}\n", -42);
	// printf(   "10) Formatage precision [.5s] : {%.s}\n", "wtf c'est la merde");
	// ft_printf("=>  Formatage precision [.5s] : {%.s}\n", "wtf c'est la merde");
	// printf(   "10) Formatage multiple [ 5d] : {% 5d}\n", 42);
	// ft_printf("=>  Formatage multiple [ 5d] : {% 5d}\n", 42);
	// printf(   "12) Formatage multiple [-10d] : {%-10d}\n", 12345);
	// ft_printf("=>  Formatage multiple [-10d] : {%-10d}\n", 12345);
	// printf(   "12) Formatage multiple [010d] : {%010d}\n", 12345);
	// ft_printf("=>  Formatage multiple [010d] : {%010d}\n", 12345);
	// printf(   "16) Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
	// ft_printf("=>  Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
	// printf(   "20) Formatage pourcent [30%%] : {%30%}\n");
	// ft_printf("=>  Formatage pourcent [30%%] : {%30%}\n");
	// printf(   "21) Formatage pourcent [30pourcent] : {%.2030%}\n");
	// ft_printf("=>  Formatage pourcent [30pourcent] : {%.2030%}\n");
	//
	// ret[0] = printf("Test de la valeur de retour [-10d s] : {%-10d} {%s}\n", 12345, str);
	// ret[1] = ft_printf("Test de la valeur de retour [-10d s] : {%-10d} {%s}\n", 12345, str);
	//
	// printf(   "23) Verification de la valeur de retour [d] : {%d}\n", ret[0]);
	// ft_printf("=>  Verification de la valeur de retour [d] : {%d}\n", ret[1]);
	printf(   "24) Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
	ft_printf("=>  Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);

	return (0);
}
