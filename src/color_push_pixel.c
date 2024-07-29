/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_push_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:20:25 by elrichar          #+#    #+#             */
/*   Updated: 2024/07/29 22:22:48 by elrichar         ###   ########.fr       */
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
	if (iterations == NB_ITERATIONS)
		push_pixel(x, y, mlx_data, COLOR_BLACK);
	else
		push_pixel(x, y, mlx_data, mlx_data->color * iterations);
	
}
