/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:51:25 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 12:48:07 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>
#include <string.h>

void fractal_error(void)
{
    printf("Usage: ./fractol [mandelbrot/julia]\n");
    printf("Example: ./fractol mandelbrot\n");
}

void fractal_init(t_data *data, char *fractal_type)
{
    if (strcmp(fractal_type, "julia") == 0)
    {
        data->fractal = "Julia";
        data->draw_fractal = &draw_julia;
    }
    else if (strcmp(fractal_type, "mandelbrot") == 0)
    {
        data->fractal = "Mandelbrot";
        data->draw_fractal = &draw_mandelbrot;
    }
    else if (strcmp(fractal_type, "burningship") == 0)
    {
        data->fractal = "Burningship";
        //data->draw_fractal = &draw_burningship;
    }
    else
    {
        printf("Fractal type not recognized.\n");
    }
}


int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2) // Verifica que haya un único argumento (fractal)
    {
        fractal_error();
        return (1);
    }
    void var_init(t_data *data);

    // Inicializar valores del fractal según el tipo
    fractal_init(&data, argv[1]);

    // Configurar eventos de ratón y teclado
    mlx_mouse_hook(data.win, mouse_control, &data);
    mlx_key_hook(data.win, keys_control, &data);

    // Dibujar el fractal seleccionado
    data.draw_fractal(&data); // Llama a la función específica del fractal
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);

    return (0);
}

