/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:09:57 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/25 14:26:03 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mandelbrot(t_mlx *mlx_data, int indicator)
{
	int	x;
	int	y;
	int	iterations;

	x = 0;
	y = 0;
	iterations = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			iterations = get_iterations(x, y, mlx_data);
			if (indicator == 1)
				color_pixel_zoom(x, y, iterations, mlx_data);
			else
				color_pixel(x, y, iterations, mlx_data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img_data.img, 0, 0);
}

int	init_minilibx(t_mlx *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (1);
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WINDOW_X, WINDOW_Y,
			"Mandelbrot Fractal");
	if (!mlx_data->mlx_win)
		return (1);
	mlx_data->img_data.img = mlx_new_image(mlx_data->mlx, WINDOW_X, WINDOW_Y);
	if (!mlx_data->img_data.img)
		return (1);
	return (0);
}

int	set_mandelbrot_vars(void)
{
	t_mlx	mlx_data;

	ft_bzero(&mlx_data, sizeof(mlx_data));
	if (init_minilibx(&mlx_data))
		return (1);
	mlx_data.img_data.addr = mlx_get_data_addr(mlx_data.img_data.img,
			&mlx_data.img_data.bpp, &mlx_data.img_data.line_length,
			&mlx_data.img_data.endian);
	complex_plane_dimensions(&mlx_data);
	(void)mlx_data.complex;
	(void)mlx_data.indicator;
	mlx_data.fractal = 1;
	set_ratio(&mlx_data);
	start_mandelbrot(&mlx_data, 0);
	mlx_hook(mlx_data.mlx_win, ButtonPress,
		ButtonPressMask, mouse_scroll, &mlx_data);
	mlx_key_hook(mlx_data.mlx_win, handle_escape, &mlx_data);
	mlx_hook(mlx_data.mlx_win, DestroyNotify, 0, handle_destroy, &mlx_data);
	mlx_hook(mlx_data.mlx_win, KeyPress, KeyPressMask,
		handle_plane_shift, &mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}

int	check_sign(char *s)
{
	if (!(*s))
		return (0);
	if (*s == '+' || *s == '-')
	{
		s++;
		if (!*s)
			return (1);
	}
	return (0);
}

int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
