/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:00:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/20 17:47:30 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int math_julia(double c_re, double c_img, int max_iter, t_data *data)
{
    int iter;
    double temp;

    temp = 0.0;
    iter = 0;
    while (data->z_re * data->z_re + data->z_img * data->z_img <= 4.0 && iter < max_iter)
    {
        //printf("Inicio de iteración: z_re: %f, z_img: %f\n", data->z_re, data->z_img);
        temp = data->z_re * data->z_re - data->z_img * data->z_img + c_re;
        data->z_img = 2.0 * data->z_re * data->z_img + c_img;
        data->z_re = temp;
        //printf("Temp: %f\n", temp);
        //printf("Iter: %d, z_re: %f, z_img: %f\n", iter, data->z_re, data->z_img);
        iter++;
    }
    //printf("z_re * z_re + z_img * z_img: %f\n", data->z_re * data->z_re + data->z_img * data->z_img);
    return(iter);
}


void draw_julia(t_data *data)
{
    int x;
    int y;
    double c_re;
    double c_img;
    int color;
    c_re = data->c_re;
    c_img = data->c_img;
    
    y = 0;
    while (y < data->win_height)
    {
        x = 0;
        while (x < data->win_width)
        {
            data->z_re = data->x_min + (x / (double) data->win_width) * (data->x_max - data->x_min);
            data->z_img = data->y_min + (y / (double) data->win_height) * (data->y_max - data->y_min);
            printf("z_re: %f, z_img: %f, c_re: %f, c_img: %f\n", data->z_re, data->z_img, c_re, c_img);
            //printf("c_re: %f, c_img: %f\n", c_re, c_img);

            data->iter = math_julia(c_re, c_img, data->max_iter, data);
            color = color_select(data);
            *(unsigned int *)(data->addr + (y * data->line_len + x * (data->bpp / 8))) = color;
            //printf("Dibujando Julia... Iteración: %d\n", data->iter);
            printf("x: %d, y: %d, color: %x\n", x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}