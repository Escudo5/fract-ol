/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:41 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/21 18:32:14 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int mouse_zoom(int button, int x, int y, t_data *data)
{
    double zoom_factor = 1.2; // Factor de ampliación o reducción
    double mouse_re;         // Coordenada real del ratón
    double mouse_im;         // Coordenada imaginaria del ratón
    mouse_re = data->x_min + x * (data->x_max - data->x_min) / data->win_width;
    mouse_im = data->y_min + y * (data->y_max - data->y_min) / data->win_height;

    if (button == 4) // Zoom in (rueda arriba)
    {
        data->x_min = mouse_re + (data->x_min - mouse_re) / zoom_factor;
        data->x_max = mouse_re + (data->x_max - mouse_re) / zoom_factor;
        data->y_min = mouse_im + (data->y_min - mouse_im) / zoom_factor;
        data->y_max = mouse_im + (data->y_max - mouse_im) / zoom_factor;
    }
    else if (button == 5) // Zoom out (rueda abajo)
    {
        data->x_min = mouse_re + (data->x_min - mouse_re) * zoom_factor;
        data->x_max = mouse_re + (data->x_max - mouse_re) * zoom_factor;
        data->y_max = mouse_im + (data->y_min - mouse_im) * zoom_factor;
        data->y_max = mouse_im + (data->y_max - mouse_im) * zoom_factor;
    }

    if (data->draw_fractal)
        data->draw_fractal(data); // Redibujar el fractal con los nuevos límites

    return (0);
}
