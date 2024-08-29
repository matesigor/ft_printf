/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:12:56 by iwietzke          #+#    #+#             */
/*   Updated: 2024/05/30 15:49:05 by iwietzke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t n, char *base)
{
	int	count;
	int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (n < 16)
	{
		write(1, "0x", 2);
		count += ft_print_digit(n, base, 'x') + 2;
	}
	else
	{
		write(1, "0x", 2);
		count += ft_print_digit(n / base_len, base, 'x') + 2;
		count += ft_print_digit(n % base_len, base, 'x');
	}
	return (count);
}
