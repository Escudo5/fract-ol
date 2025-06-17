/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:05:42 by smarquez          #+#    #+#             */
/*   Updated: 2024/11/07 17:33:17 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
char	ft_putchar(int c);
int		ft_putnbru(unsigned int nbr);
int		ft_putptr(void *ptr);
int		ft_hexadec(unsigned long nbr, int upper);

#endif