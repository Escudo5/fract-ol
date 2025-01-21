/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/21 11:32:33 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <math.h>
#include <math.h>

#include "../includes/fractol.h"
#include <math.h>

int color_select(t_data *data)
{
    int r, g, b;
    double t;

    // Evitar división por cero y calcular nivel de escape
    if (data->max_iter == 0 || data->iter == data->max_iter)
        return 0x000000; // Negro para puntos dentro del conjunto

    // Calcular proporción de iteraciones actuales frente a las máximas
    t = (double)data->iter / data->max_iter;

    // Gradiente de colores basado en interpolación suave
    r = (int)(9 * (1 - t) * t * t * t * 255);
    g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    // Combinar componentes RGB en un entero
    return (r << 16) | (g << 8) | b;
}


