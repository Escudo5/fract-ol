/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:00:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:46:49 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	math_julia(double c_re, double c_img, int max_iter, t_data *data)
{
	int		iter;
	double	temp;

	temp = 0.0;
	iter = 0;
	while (data->z_re * data->z_re + data->z_img * data->z_img <= 4.0
		&& iter < max_iter)
	{
		temp = data->z_re * data->z_re - data->z_img * data->z_img + c_re;
		data->z_img = 2.0 * data->z_re * data->z_img + c_img;
		data->z_re = temp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_data *data)
{
	int		x;
	int		y;
	double	c_re;
	double	c_img;

	c_re = data->c_re;
	c_img = data->c_img;
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			data->z_re = data->x_min + (x / (double)data->win_width)
				* (data->x_max - data->x_min);
			data->z_img = data->y_min + (y / (double)data->win_height)
				* (data->y_max - data->y_min);
			data->iter = math_julia(c_re, c_img, data->max_iter, data);
			data->color = color_select(data);
			data->pixels[y * data->win_width + x] = data->color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
