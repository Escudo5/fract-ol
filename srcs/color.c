/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/20 17:50:11 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <math.h>

int color_select(t_data *data)
{
    int r, g, b;
    double t; // Factor de interpolación para el gradiente

    // Calcular un factor t basado en la relación iter / max_iter
    if (data->iter == data->max_iter)
    {
        r = 0;
        g = 0;
        b = 0; // Puntos dentro del conjunto serán negros
    }
    else
    {
        t = (double)data->iter / data->max_iter; // Normaliza iteraciones entre 0 y 1
        t = sqrt(t); // Suaviza la transición de colores con una raíz cuadrada

        // Gradiente basado en t
        r = (int)(9 * (1 - t) * t * t * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }

    return (r << 16) | (g << 8) | b; // Devuelve el color como un entero
}
