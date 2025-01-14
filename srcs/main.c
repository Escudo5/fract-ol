/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/14 12:22:51 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp, line_len, endian;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Fract-ol");

    img = mlx_new_image(mlx, 800, 600);
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

    // Dibujar un píxel en el buffer
    int x = 200; // Coordenada X
    int y = 200; // Coordenada Y
    int color = 0x00FF00; // Verde
    *(unsigned int *)(addr + (y * line_len + x * (bpp / 8))) = color;

    mlx_put_image_to_window(mlx, win, img, 0, 0); // Mostrar la imagen en la ventana
    mlx_loop(mlx);

    return (0);
}
