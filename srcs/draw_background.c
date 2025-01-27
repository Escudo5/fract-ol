/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:42:02 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 16:26:37 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_background(t_data *data)
{
    int x;
    int y;
    int color;

    y = 0;
    while (y < data->win_height)
    {
        x = 0;
        while (x < data->win_width)
        {
            // Calcula un color simple basado en las coordenadas X e Y
            color = (x * 255 / data->win_width) << 16 | (y * 255 / data->win_height);
            *(unsigned int *)(data->addr + (y * data->line_len + x * (data->bpp / 8))) = color;
            x++;
        }
        y++;
    }
}
