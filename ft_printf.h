/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:02:35 by iwietzke          #+#    #+#             */
/*   Updated: 2024/05/30 16:23:28 by iwietzke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> //malloc free
# include <stdio.h>
# include <unistd.h> //write
# include <stdarg.h> // variadic stuff
# include <limits.h> // INT_MAX

# define DECIMAL "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_print_format(char specifier, va_list ap);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digit(long n, char *base, char specifier);
int		ft_print_ptr(size_t n, char *base);
size_t	ft_strlen(const char *str);

#endif
