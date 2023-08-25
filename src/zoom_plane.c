/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:00:05 by elrichar          #+#    #+#             */
/*   Updated: 2023/08/24 12:23:17 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_mlx *mlx_data, double zoom)
{
	double	a;
	double	b;
	double	xcursor;
	double	ycursor;

	xcursor = x / (double)WINDOW_X;
	ycursor = y / (double)WINDOW_Y;
	a = (zoom * (mlx_data->real_max - mlx_data->real_min))
		- (mlx_data->real_max - mlx_data->real_min);
	b = (zoom * (mlx_data->imag_max - mlx_data->imag_min))
		- (mlx_data->imag_max - mlx_data->imag_min);
	mlx_data->real_min = mlx_data->real_min - (a * xcursor);
	mlx_data->real_max = mlx_data->real_max + (a * (1 - xcursor));
	mlx_data->imag_max = mlx_data->imag_max + (b * ycursor);
	mlx_data->imag_min = mlx_data->imag_min - (b * (1 - ycursor));
	mlx_data->ratio_x = (mlx_data->real_max - mlx_data->real_min) / WINDOW_X;
	mlx_data->ratio_y = (mlx_data->imag_max - mlx_data->imag_min) / WINDOW_Y;
	if (mlx_data->fractal == 1)
		start_mandelbrot(mlx_data, 1);
	else if (mlx_data->fractal == 2)
		start_julia(mlx_data);
	else if (mlx_data->fractal == 3)
		start_burning_ship(mlx_data);
}

void	zoom_out(int x, int y, t_mlx *mlx_data, double zoom)
{
	double	a;
	double	b;
	double	xcursor;
	double	ycursor;

	xcursor = x / (double)WINDOW_X;
	ycursor = y / (double)WINDOW_Y;
	a = (1 / zoom * (mlx_data->real_max - mlx_data->real_min))
		- (mlx_data->real_max - mlx_data->real_min);
	b = (1 / zoom * (mlx_data->imag_max - mlx_data->imag_min))
		- (mlx_data->imag_max - mlx_data->imag_min);
	mlx_data->real_min = mlx_data->real_min - (a * xcursor);
	mlx_data->real_max = mlx_data->real_max + (a * (1 - xcursor));
	mlx_data->imag_max = mlx_data->imag_max + (b * ycursor);
	mlx_data->imag_min = mlx_data->imag_min - (b * (1 - ycursor));
	mlx_data->ratio_x = (mlx_data->real_max - mlx_data->real_min) / WINDOW_X;
	mlx_data->ratio_y = (mlx_data->real_max - mlx_data->real_min) / WINDOW_X;
	if (mlx_data->fractal == 1)
		start_mandelbrot(mlx_data, 1);
	else if (mlx_data->fractal == 2)
		start_julia(mlx_data);
	else if (mlx_data->fractal == 3)
		start_burning_ship(mlx_data);
}
