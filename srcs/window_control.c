/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:41:05 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:41:44 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	exit(0);
}

int	refresh(t_data *data)
{
	if (ft_strncmp(data->fractal, "Burningship", 11) == 0)
		draw_burning(data);
	if (ft_strncmp(data->fractal, "Mandelbrot", 10) == 0)
		draw_mandelbrot(data);
	if (ft_strncmp(data->fractal, "Julia", 5) == 0)
		draw_julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
