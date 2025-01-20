/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/20 16:35:24 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(void)
{
    t_data data;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Fract-ol");
    data.img = mlx_new_image(data.mlx, 800, 600);
    // Obtener buffer de datos de la imagen. Sirve para sacar los colores.
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    
    data.x_min = -2.0;
    data.x_max = 1.0;
    data.y_min = -1.5;
    data.y_max = 1.5;
    data.max_iter = 100;
    data.win_width = 800;
    data.win_height = 600;

    // Dibujar un píxel en el buffer
    /*
    int x = 200; // Coordenada X
    int y = 200; // Coordenada Y
    int color = 0x00FF00; // Verde
    *(unsigned int *)(data.addr + (y * data.line_len + x * (data.bpp / 8))) = color;
    
    
    draw_background(&data);
    mlx_loop(data.mlx);*/
    draw_mandelbrot(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0); // Mostrar la imagen en la ventana
    mlx_loop (data.mlx);

    return (0);
}

