/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:29:00 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/15 15:38:40 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

int			ft_printf(const char *str, ...);
int			ft_parse(int i, const char *str, va_list ap, int *count);
int			ft_check_flag(const char *str, va_list ap, int i, int *off, int *sign);

//printer
void		ft_putchar(char c);
void		ft_putstr(char *s, int off);
void		ft_putnbr(int n, int off);
void		ft_putnbr_u(int n);
void		ft_put_hex(long unsigned int num, char *base);
void		ft_put_add(va_list ap);

int			ft_atoi(const char *str, int *i);

//size
size_t		ft_strlen(const char *s);
size_t		ft_intlen(int n);

size_t		ft_is_option(char c);
size_t		ft_is_flag(char c);

#endif
