/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:35:58 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 15:52:36 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
# include "../custom-libft/libft.h"
#include <math.h>


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
    char *fractal;
    double  zoom_factor;
    void (*draw_fractal)(struct t_data *);
}t_data;

void draw_background(t_data *data);
void draw_mandelbrot(t_data *data);
void draw_julia(t_data *data);
void	draw_burning(t_data *data);
int color_select(t_data *data);
void draw_background(t_data *data);
//void zoom_in(t_data *data, int x, int y);
//void zoom_out(t_data *data, int x, int y);
int mouse_control(int button, int x, int y, void *param);
int keys_control(int keycode, t_data *data);
void var_init(t_data *data);
int refresh(t_data *data);



#endif 