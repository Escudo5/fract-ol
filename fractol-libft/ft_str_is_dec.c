/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:47:00 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:38:51 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_dec(char *nb)
{
	int	point_found;

	point_found = 0;
	if (*nb == '+' || *nb == '-')
		nb++;
	if (*nb == '\0')
		return (0);
	while (*nb)
	{
		if (*nb == '.')
		{
			if (point_found)
				return (0);
			point_found = 1;
		}
		else if (!(ft_isdigit(*nb)))
			return (0);
		nb++;
	}
	return (1);
}
