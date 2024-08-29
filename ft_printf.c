/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:12:22 by iwietzke          #+#    #+#             */
/*   Updated: 2024/06/15 15:27:16 by iwietzke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		count += ft_print_digit((va_arg(ap, int)), DECIMAL, specifier);
	else if (specifier == 'x')
		count += ft_print_digit((va_arg(ap, unsigned int)), HEXL,
				specifier);
	else if (specifier == 'X')
		count += ft_print_digit((va_arg(ap, unsigned int)), HEXU,
				specifier);
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(ap, size_t), HEXL);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

/* int main() {
    printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 1977);
	printf ("Preceding with zeros: %010d \n", 1977);
	printf ("Some different radices: %d %x %o \n", 100, 100, 100);
	printf ("Some different radices: %#x %#o \n", 100, 100);
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Width trick: %*d \n", 5, 10);
	printf ("%s \n", "A string");

	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977);
	ft_printf ("Some different radices: %d %x %o \n", 100, 100, 100);
	ft_printf ("Some different radices: %#x %#o \n", 100, 100);
	ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("Width trick: %*d \n", 5, 10);
	ft_printf ("%s \n", "A string");
	return 0;
} */