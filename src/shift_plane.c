/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:06:21 by elrichar          #+#    #+#             */
/*   Updated: 2023/08/24 11:44:24 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_plane_shift(int keycode, t_mlx *mlx_data)
{
	if (keycode == UP)
		move_plane_up(mlx_data);
	else if (keycode == DOWN)
		move_plane_down(mlx_data);
	else if (keycode == RIGHT)
		move_plane_right(mlx_data);
	else if (keycode == LEFT)
		move_plane_left(mlx_data);
	return (0);
}

void	move_plane_up(t_mlx *mlx_data)
{
	mlx_data->ratio_y = mlx_data->imag_max - mlx_data->imag_min;
	mlx_data->imag_max += mlx_data->ratio_y * 0.05;
	mlx_data->imag_min += mlx_data->ratio_y * 0.05;
	if (mlx_data->fractal == 1)
		start_mandelbrot(mlx_data, 0);
	else if (mlx_data->fractal == 2)
		start_julia(mlx_data);
	else if (mlx_data->fractal == 3)
		start_burning_ship(mlx_data);
}

void	move_plane_down(t_mlx *mlx_data)
{
	mlx_data->ratio_y = mlx_data->imag_max - mlx_data->imag_min;
	mlx_data->imag_max -= mlx_data->ratio_y * 0.05;
	mlx_data->imag_min -= mlx_data->ratio_y * 0.05;
	if (mlx_data->fractal == 1)
		start_mandelbrot(mlx_data, 0);
	else if (mlx_data->fractal == 2)
		start_julia(mlx_data);
	else if (mlx_data->fractal == 3)
		start_burning_ship(mlx_data);
}

void	move_plane_right(t_mlx *mlx_data)
{
	mlx_data->ratio_x = mlx_data->real_max - mlx_data->real_min;
	mlx_data->real_max += mlx_data->ratio_x * 0.05;
	mlx_data->real_min += mlx_data->ratio_x * 0.05;
	mlx_data->ratio_x = (mlx_data->real_max - mlx_data->real_min) / WINDOW_X;
	if (mlx_data->fractal == 1)
		start_mandelbrot(mlx_data, 0);
	else if (mlx_data->fractal == 2)
		start_julia(mlx_data);
	else if (mlx_data->fractal == 3)
		start_burning_ship(mlx_data);
}

void	move_plane_left(t_mlx *mlx_data)
{
	mlx_data->ratio_x = mlx_data->real_max - mlx_data->real_min;
	mlx_data->real_max -= mlx_data->ratio_x * 0.05;
	mlx_data->real_min -= mlx_data->ratio_x * 0.05;
	mlx_data->ratio_x = (mlx_data->real_max - mlx_data->real_min) / WINDOW_X;
	if (mlx_data->fractal == 1)
		start_mandelbrot(mlx_data, 0);
	else if (mlx_data->fractal == 2)
		start_julia(mlx_data);
	else if (mlx_data->fractal == 3)
		start_burning_ship(mlx_data);
}
