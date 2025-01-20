/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/20 16:53:04 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int color_select(t_data *data)
{
    int r, g, b;

    if (data->iter == data->max_iter)
    {
        r = 0;
        g = 0;
        b = 0;  // Puntos en el conjunto Mandelbrot serán negros
    }
    else
    {
        r = (data->iter * 10) % 255;  // Gradiente de rojo
        g = (data->iter * 5) % 255;   // Gradiente de verde
        b = (data->iter * 20) % 255;  // Gradiente de azul
    }

    return (r << 16) | (g << 8) | b;  // Devuelve el color como un entero
}

