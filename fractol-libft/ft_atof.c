/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:30:04 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:40:20 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	take_sign(char *nb, int *i)
{
	double	sign;

	sign = 1.0;
	if (nb[*i] == '-' || nb[*i] == '+')
	{
		if (nb[*i] == '-')
			sign = -1.0;
		(*i)++;
	}
	return (sign);
}

static double	handle_decimal_part(char *nb, int *i)
{
	double	decimal_part;
	double	result;

	decimal_part = 1.0;
	result = 0.0;
	while (nb[*i] && ft_isdigit(nb[*i]))
	{
		decimal_part *= 10;
		result += (nb[*i] - '0') / decimal_part;
		(*i)++;
	}
	return (result);
}

double	ft_atof(char *nb)
{
	int		i;
	double	result;
	double	sign;

	i = 0;
	result = 0.0;
	sign = 1.0;
	sign = take_sign(nb, &i);
	while (nb[i] && ft_isdigit(nb[i]))
	{
		result = result * 10 + (nb[i] - '0');
		i++;
	}
	if (nb[i] == '.')
	{
		i++;
		result += handle_decimal_part(nb, &i);
	}
	return (result * sign);
}
