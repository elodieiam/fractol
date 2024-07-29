/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_push_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:20:25 by elrichar          #+#    #+#             */
/*   Updated: 2024/07/29 21:16:17 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	push_pixel(int x, int y, t_mlx *mlx_data, int color)
{
	char	*pixel;

	pixel = mlx_data->img_data.addr + (y * mlx_data->img_data.line_length
			+ x * (mlx_data->img_data.bpp / 8));
	*(unsigned int *)pixel = color;
}

void	color_pixel_julia(int x, int y, int iterations, t_mlx *mlx_data)
{
	if (iterations == NB_ITERATIONS)
		push_pixel(x, y, mlx_data, COLOR_BLACK);
	else
		push_pixel(x, y, mlx_data, mlx_data->color * iterations);
}

void	color_pixel(int x, int y, double iterations, t_mlx *mlx_data)
{
	if (iterations == NB_ITERATIONS)
		push_pixel(x, y, mlx_data, COLOR_BLACK);
	else
		push_pixel(x, y, mlx_data, mlx_data->color * iterations);
}

void	color_pixel_burning(int x, int y, double iterations, t_mlx *mlx_data)
{
	static double	h;

	if (iterations == NB_ITERATIONS)
		push_pixel(x, y, mlx_data, COLOR_BLACK);
	else
	{
		h += 0.02;
		if (iterations < NB_ITERATIONS / 10)
			push_pixel(x, y, mlx_data, COLOR_BLACK);
		else if (iterations < NB_ITERATIONS / 7.5)
			push_pixel(x, y, mlx_data, COLOR_YELLOW + h);
		else if (iterations < NB_ITERATIONS / 5)
			push_pixel(x, y, mlx_data, COLOR_CYAN + h);
		else if (iterations < NB_ITERATIONS / 2.5)
			push_pixel(x, y, mlx_data, COLOR_MAGENTA + h);
		else if (iterations < NB_ITERATIONS / 1.25)
			push_pixel(x, y, mlx_data, COLOR_ORANGE + h);
		else
			push_pixel(x, y, mlx_data, COLOR_MAGENTA + h);
	}
}
