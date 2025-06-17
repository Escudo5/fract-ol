/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:53:46 by smarquez          #+#    #+#             */
/*   Updated: 2024/11/07 16:08:28 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int nbr)
{
	int	printed_chars;

	printed_chars = 0;
	if (nbr > 9)
		printed_chars += ft_putnbru(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	printed_chars++;
	return (printed_chars);
}
