/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:35:58 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/20 17:03:22 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct t_data
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    int     win_width;
    int     win_height;
    int iter;
    int max_iter;
    double c_re;
    double c_img;
    double z_img;
    double z_re;
    double x_min;
    double y_min;
    double x_max;
    double y_max;
    //int colour;
    int size_x;
    int size_y;
    int *pixels;
    
}t_data;

void draw_background(t_data *data);
void draw_mandelbrot(t_data *data);
int color_select(t_data *data);
void draw_background(t_data *data);
void draw_julia(t_data *data);







#endif 