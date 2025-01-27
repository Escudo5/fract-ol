/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:04:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:50 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include "fractol.h"


// Control de flechas para mover el fractal
int arrow_control(int keycode, t_data *data)
{
    double move;

    move = 0.1;
    if (keycode == XK_Up) // Mover hacia arriba
    {
        data->y_max -= move;
        data->y_min -= move;
    }
    else if (keycode == XK_Down) // Mover hacia abajo
    {
        data->y_max += move;
        data->y_min += move;
    }
    else if (keycode == XK_Right) // Mover hacia la derecha
    {
        data->x_max += move;
        data->x_min += move;
    }
    else if (keycode == XK_Left) // Mover hacia la izquierda
    {
        data->x_max -= move;
        data->x_min -= move;
    }
    return (0);
}

// Salir del programa con la tecla Esc
int esc_control(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

// Manejo general de teclas
int keys_control(int keycode, t_data *data)
{
    if (keycode == XK_Escape) // Salir
        esc_control(keycode, data);
    else // Mover fractal con flechas
        arrow_control(keycode, data);
    return (0);
}


