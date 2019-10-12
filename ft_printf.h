/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:29:00 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/12 20:15:23 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

int			ft_parse(int i, const char *str, va_list ap);
int			ft_check_flag(const char *str, int i);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbr(int n);
void		ft_putnbr_u(int n);
void		ft_put_hex(long unsigned int num, char *base);
void		ft_put_add(va_list ap);
size_t		ft_is_option(char c);
int			ft_atoi(const char *str, int *i);

#endif
