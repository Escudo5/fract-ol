/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:04:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:46:01 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "fractol.h"

int	arrow_control(int keycode, t_data *data)
{
	double	move;

	move = 0.1;
	if (keycode == XK_Up)
	{
		data->y_max -= move;
		data->y_min -= move;
	}
	else if (keycode == XK_Down)
	{
		data->y_max += move;
		data->y_min += move;
	}
	else if (keycode == XK_Right)
	{
		data->x_max += move;
		data->x_min += move;
	}
	else if (keycode == XK_Left)
	{
		data->x_max -= move;
		data->x_min -= move;
	}
	return (0);
}

int	c_color_control(int keycode, t_data *data)
{
	if (keycode == XK_c && ft_strncmp(data->fractal, "Burningship", 11) == 0)
	{
		data->color_set = (data->color_set + 1) % 2;
		draw_burning(data);
	}
	if (keycode == XK_c && ft_strncmp(data->fractal, "Mandelbrot", 10) == 0)
	{
		data->color_set = (data->color_set + 1) % 2;
		draw_mandelbrot(data);
	}
	if (keycode == XK_c && ft_strncmp(data->fractal, "Julia", 5) == 0)
	{
		data->color_set = (data->color_set + 1) % 2;
		draw_julia(data);
	}
	return (0);
}

int	esc_control(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	keys_control(int keycode, t_data *data)
{
	if (keycode == XK_c)
		c_color_control(keycode, data);
	if (keycode == XK_Escape)
		esc_control(keycode, data);
	else
		arrow_control(keycode, data);
	return (0);
}
