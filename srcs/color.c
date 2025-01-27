/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:15:10 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>


static int	color_org(t_data *data)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)data->iter / (double)data->max_iter;
	if (data->iter == data->max_iter)
    return (0xFF0000); // Rojo sólido
	red = (int)((sin(t * M_PI * 2) * 0.5 + 0.5) * 255);
	green = (int)((sin((t + 0.33) * M_PI * 2) * 0.5 + 0.5) * 255);
	blue = (int)((sin((t + 0.66) * M_PI * 2) * 0.5 + 0.5) * 255);
	return ((red << 16) | (green << 8) | blue);
}

static int	color_variation(t_data *data)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)data->iter / (double)data->max_iter;
	if (data->iter == data->max_iter)
    return (0xFF0000); // Rojo sólido
	red = (int)((sin(t * M_PI * 3) * 0.5 + 0.5) * 255);
	green = (int)((sin((t + 0.5) * M_PI * 2) * 0.5 + 0.5) * 255);
	blue = (int)((sin((t + 1.0) * M_PI * 2) * 0.5 + 0.5) * 255);
	return ((red << 16) | (green << 8) | blue);
}

int color_select(t_data *data)
{
    int color;
    
    if (data->color_set == 0)
        color = color_org(data);
    else
        color = color_variation(data);
     //Print para ver el color calculado
    //printf("Color: %d\n", color);

    return color;
}



