/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:50 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/23 11:20:08 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	printed_chars;

	printed_chars = 0;
	if (n == -2147483648)
	{
		printed_chars += ft_putchar('-');
		printed_chars += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		printed_chars += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		printed_chars += ft_putnbr(n / 10);
	}
	printed_chars += ft_putchar((n % 10) + '0');
	return (printed_chars);
}
