/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:29:00 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/21 00:44:09 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

# define BUFFER_SIZE 256

typedef struct	s_printf
{
	char	*s;
	char	*tmp;
	char	*num;
	int		width;
	int		precision;
	int		precision_width;
	int		precision_parsing;
	int		minus;
	int		zero;
	int		offset;
	int		plus;
	int		space;
	int		i;
}				t_printf;

/*
** main func
*/

int				ft_printf(const char *str, ...);
void			ft_str_it(va_list ap, t_printf *tab, const char *str);
void			ft_parse(const char *str, va_list ap, t_printf *tab);
void			ft_check_flag(const char *str, va_list ap, t_printf *tab);

/*
** libft
*/

void			ft_putstr_len(const char *s, int count);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_len(char const *s1, char const *s2, int len);
int				ft_atoi(const char *str, int *i);
int				ft_strlen(const char *s);
size_t			ft_intlen(int n);
size_t			ft_uintlen(unsigned int n);
size_t			ft_hexlen(long unsigned n);

char			*ft_join_char(char c, char *str);
char	*ft_strdup(const char *s1);

void			ft_print_char(char c, t_printf *tab);
void			ft_print_str(const char *s, t_printf *tab);
void			ft_print_nbr(int n, t_printf *tab);
void			ft_print_nbr_u(unsigned int n, t_printf *tab);
void			ft_print_add(long unsigned add, t_printf *tab);
void			ft_print_hex(unsigned int hex, int uppercase, t_printf *tab);
char			*ft_print_sp(int n, int zero);

/*
** printer
*/

char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa_hex(long unsigned num, char *base);

/*
** other
*/

void			ft_set_precision(t_printf *tab);
void			ft_reset_flags(t_printf *tab);
size_t			ft_is_flag(char c);
size_t			ft_is_from_pf(char c);

#endif
