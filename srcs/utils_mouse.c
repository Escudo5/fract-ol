/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:41 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:46:35 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "fractol.h"

void	zoom_in(t_data *data, int x, int y)
{
	double	mouse_re;
	double	mouse_img;

	mouse_re = data->x_min + (x / (double)data->win_width) * (data->x_max
			- data->x_min);
	mouse_img = data->y_min + (y / (double)data->win_height) * (data->y_max
			- data->y_min);
	data->zoom_factor *= 1.1;
	data->x_min = mouse_re - (mouse_re - data->x_min) / 1.1;
	data->x_max = mouse_re + (data->x_max - mouse_re) / 1.1;
	data->y_min = mouse_img - (mouse_img - data->y_min) / 1.1;
	data->y_max = mouse_img + (data->y_max - mouse_img) / 1.1;
}

void	zoom_out(t_data *data, int x, int y)
{
	double	mouse_re;
	double	mouse_img;

	mouse_re = data->x_min + (x / (double)data->win_width) * (data->x_max
			- data->x_min);
	mouse_img = data->y_min + (y / (double)data->win_height) * (data->y_max
			- data->y_min);
	data->zoom_factor /= 1.1;
	data->x_min = mouse_re - (mouse_re - data->x_min) * 1.1;
	data->x_max = mouse_re + (data->x_max - mouse_re) * 1.1;
	data->y_min = mouse_img - (mouse_img - data->y_min) * 1.1;
	data->y_max = mouse_img + (data->y_max - mouse_img) * 1.1;
}

int	mouse_control(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (x < 0 || x >= data->win_width || y < 0 || y >= data->win_height)
		return (0);
	if (button == 4)
		zoom_in(data, x, y);
	if (button == 5)
		zoom_out(data, x, y);
	return (0);
}
