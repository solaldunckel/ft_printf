/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:29:00 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/18 22:22:06 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct	s_printf
{
	int width;
	int	precision;
	int	precision_width;
	int	precision_parsing;
	int minus;
	int zero;
	int count;
	int i;
}				t_printf;

/*
** main func
*/

int				ft_printf(const char *str, ...);
int				ft_parse(const char *str, va_list ap, t_printf *tab);
int				ft_check_flag(const char *str, va_list ap, t_printf *tab);
void			ft_str_it(va_list ap, t_printf *tab, const char *str);

/*
** libft
*/

void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putnbr(int n);
int				ft_atoi(const char *str, int *i);
int				ft_strlen(const char *s);
size_t			ft_intlen(int n);

/*
** printer
*/

void			ft_putnbr_u(unsigned int n);
void			ft_put_hex(long unsigned num, char *base);
void			ft_putstr_p(const char *s, t_printf *tab);
void			ft_print_str(const char *s, t_printf *tab);
void			ft_print_nbr(int n, t_printf *tab);
void			ft_print_percent(char c, t_printf *tab);
void			ft_print_add(long unsigned add, t_printf *tab);
void			ft_print_hex(unsigned int hex, int base, t_printf *tab);

/*
** other
*/

size_t			ft_hexlen(long unsigned n);
void			ft_set_precision(t_printf *tab);
void			ft_reset_flags(t_printf *tab);
size_t			ft_is_flag(char c);

#endif
