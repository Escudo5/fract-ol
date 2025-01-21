/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/21 13:17:40 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(void)
{
    t_data data;
    data.mlx = mlx_init();
    data.win_width = 800;
    data.win_height = 600;
    data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Fract-ol");
    data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
    // Obtener buffer de datos de la imagen. Sirve para sacar los colores.
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    
    data.x_min = -2.0;
    data.x_max = 1.0;
    data.y_min = -1.5;
    data.y_max = 1.5;
    data.max_iter = 100;

    //consts de julia
    data.c_re = -1.476;
    data.c_img = 0.0;
    mlx_hook(data.mlx, 4, 0, mouse_zoom, &data);

    draw_julia(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0); // Mostrar la imagen en la ventana
    mlx_loop (data.mlx);

    return (0);
}

