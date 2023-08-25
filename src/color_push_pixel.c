/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_push_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:20:25 by elrichar          #+#    #+#             */
/*   Updated: 2023/08/24 11:48:34 by elrichar         ###   ########.fr       */
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
	int				color;
	int				palette[7];
	static double	h = 0;

	h += 0.002;
	palette[0] = COLOR_BLACK;
	palette[1] = COLOR_BLACK;
	palette[2] = COLOR_BLACK;
	palette[3] = COLOR_YELLOW + h;
	palette[4] = COLOR_CYAN + h;
	palette[5] = COLOR_MAGENTA + h;
	palette[6] = COLOR_ORANGE + h;
	if (iterations >= NB_ITERATIONS)
		color = COLOR_BLACK;
	else
		color = palette[iterations % 6];
	push_pixel(x, y, mlx_data, color);
}

void	color_pixel_zoom(int x, int y, double iterations, t_mlx *mlx_data)
{
	static double	g;

	if (iterations == NB_ITERATIONS)
		push_pixel(x, y, mlx_data, COLOR_BLACK);
	else
	{
		g += 0.02;
		if (iterations < NB_ITERATIONS / 10)
			push_pixel(x, y, mlx_data, COLOR_BLACK);
		else if (iterations < NB_ITERATIONS / 7.5)
			push_pixel(x, y, mlx_data, COLOR_YELLOW + (g));
		else if (iterations < NB_ITERATIONS / 5)
			push_pixel(x, y, mlx_data, COLOR_CYAN + (g));
		else if (iterations < NB_ITERATIONS / 2.5)
			push_pixel(x, y, mlx_data, COLOR_MAGENTA + (g));
		else if (iterations < NB_ITERATIONS / 1.25)
			push_pixel(x, y, mlx_data, COLOR_ORANGE + (g));
		else
			push_pixel(x, y, mlx_data, COLOR_MAGENTA + (g));
	}
}

void	color_pixel(int x, int y, double iterations, t_mlx *mlx_data)
{
	if (iterations == NB_ITERATIONS)
		push_pixel(x, y, mlx_data, COLOR_BLACK);
	else
	{
		if (iterations < NB_ITERATIONS / 10)
			push_pixel(x, y, mlx_data, COLOR_BLACK);
		else if (iterations < NB_ITERATIONS / 7.5)
			push_pixel(x, y, mlx_data, COLOR_YELLOW);
		else if (iterations < NB_ITERATIONS / 5)
			push_pixel(x, y, mlx_data, COLOR_CYAN);
		else if (iterations < NB_ITERATIONS / 2.5)
			push_pixel(x, y, mlx_data, COLOR_MAGENTA);
		else if (iterations < NB_ITERATIONS / 1.25)
			push_pixel(x, y, mlx_data, COLOR_ORANGE);
		else
			push_pixel(x, y, mlx_data, COLOR_MAGENTA);
	}
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
