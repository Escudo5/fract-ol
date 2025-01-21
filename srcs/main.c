/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/21 18:57:49 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
    {
        printf("Usage: ./fractol [mandelbrot/julia]\n");
        return (1);
    }

    data.mlx = mlx_init();
    data.win_width = 800;
    data.win_height = 600;
    data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Fract-ol");
    data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);

    data.x_min = -2.0;
    data.x_max = 1.0;
    data.y_min = -1.5;
    data.y_max = 1.5;
    data.max_iter = 100;

    if (strcmp(argv[1], "julia") == 0)
    {
        data.c_re = -1.476; // Constantes específicas de Julia
        data.c_img = 0.0;
        data.draw_fractal = &draw_julia;
    }
    else if (strcmp(argv[1], "mandelbrot") == 0)
    {
        data.draw_fractal = &draw_mandelbrot;
    }
    else
    {
        printf("Error: Fractal not recognized. Use 'mandelbrot' or 'julia'.\n");
        return (1);
    }

    mlx_mouse_hook(data.win, mouse_control, &data);

    data.draw_fractal(&data); // Llama a la función del fractal seleccionado
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);

    return (0);
}


