/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:50:08 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 18:48:41 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	fun_burning(char **argv)
{
	t_data	data;

	var_init(&data);
	data.fractal = "Burningship";
	data.win_width = ft_atoi(argv[2]);
	data.win_height = ft_atoi(argv[3]);
	data.size_x = data.win_width;
	data.size_y = data.win_height;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y,
			"Burningship");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.pixels = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.line_len,
			&data.endian);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win, mouse_control, &data);
	mlx_key_hook(data.win, keys_control, &data);
	mlx_loop_hook(data.mlx, &refresh, &data);
	mlx_loop(data.mlx);
	return (0);
}

static int	fun_julia(char **argv)
{
	t_data	data;

	var_init(&data);
	data.fractal = "Julia";
	data.win_width = ft_atoi(argv[2]);
	data.win_height = ft_atoi(argv[3]);
	data.c_re = ft_atof(argv[4]);
	data.c_img = ft_atof(argv[5]);
	data.size_x = data.win_width;
	data.size_y = data.win_height;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "julia");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.pixels = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.line_len,
			&data.endian);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win, mouse_control, &data);
	mlx_key_hook(data.win, keys_control, &data);
	mlx_loop_hook(data.mlx, &refresh, &data);
	mlx_loop(data.mlx);
	return (0);
}

static int	fun_mandel(char **argv)
{
	t_data	data;

	var_init(&data);
	data.fractal = "Mandelbrot";
	data.win_width = ft_atoi(argv[2]);
	data.win_height = ft_atoi(argv[3]);
	data.size_x = data.win_width;
	data.size_y = data.win_height;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "Mandelbrot");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.pixels = (int *)mlx_get_data_addr(data.img, &data.bpp, &data.line_len,
			&data.endian);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win, mouse_control, &data);
	mlx_key_hook(data.win, keys_control, &data);
	mlx_loop_hook(data.mlx, &refresh, &data);
	mlx_loop(data.mlx);
	return (0);
}

static void	fun_error(void)
{
	ft_printf("\n Error in parameters:\n");
	ft_printf("\n Please insert parameters like this:\n");
	ft_printf("\n	-Mandelbrot (height window) (width window).\n");
	ft_printf("\n	-Burningship (height window) (width window).\n");
	ft_printf("\n	-Julia (height window) (width window)"
		" (real number) (imaginari number).\n");
	ft_printf("\n Thanks. :)\n\n");
}

int	main(int argc, char **argv)
{
	if (argc != 4 && argc != 6)
	{
		fun_error();
		return (0);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0 && ft_str_isdigit(argv[2])
		&& ft_str_isdigit(argv[3]))
		fun_mandel(argv);
	if (ft_strncmp(argv[1], "Julia", 5) == 0 && ft_str_isdigit(argv[2])
		&& ft_str_isdigit(argv[3]) && ft_str_is_dec(argv[4])
		&& ft_str_is_dec(argv[5]))
		fun_julia(argv);
	if (ft_strncmp(argv[1], "Burningship", 11) == 0 && ft_str_isdigit(argv[2])
		&& ft_str_isdigit(argv[3]))
		fun_burning(argv);
	else
		fun_error();
	return (0);
}
