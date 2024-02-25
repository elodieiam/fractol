/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:14:30 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/25 14:27:12 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iterations_ship(int x, int y, t_mlx *mlx_data)
{
	t_complex	c;
	t_complex	z;
	int			iterations;

	c.real = mlx_data->real_min + x * (mlx_data->ratio_x);
	c.imag = mlx_data->imag_max - y * (mlx_data->ratio_x);
	z.real = 0.0;
	z.imag = 0.0;
	iterations = nb_iterations_burning(&c, &z);
	return (iterations);
}

void	start_burning_ship(t_mlx *mlx_data)
{
	int	x;
	int	y;
	int	iterations;

	x = 0;
	y = 0;
	iterations = 0;
	while (y < WINDOW_Y_S)
	{
		x = 0;
		while (x < WINDOW_X_S)
		{
			iterations = get_iterations_ship(x, y, mlx_data);
			color_pixel_burning(x, y, iterations, mlx_data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img_data.img, 0, 0);
}

static int	init_minilibx(t_mlx *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (1);
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WINDOW_X_S, WINDOW_Y_S,
			"Burning Ship Fractal");
	if (!mlx_data->mlx_win)
		return (1);
	mlx_data->img_data.img = mlx_new_image(mlx_data->mlx,
			WINDOW_X_S, WINDOW_Y_S);
	if (!mlx_data->img_data.img)
		return (1);
	return (0);
}

int	set_burning_fractal_vars(void)
{
	t_mlx	mlx_data;

	ft_bzero(&mlx_data, sizeof(mlx_data));
	if (init_minilibx(&mlx_data))
		return (1);
	mlx_data.img_data.addr = mlx_get_data_addr(mlx_data.img_data.img,
			&mlx_data.img_data.bpp, &mlx_data.img_data.line_length,
			&mlx_data.img_data.endian);
	complex_plane_dimensions_burning(&mlx_data);
	(void)mlx_data.complex;
	(void)mlx_data.indicator;
	mlx_data.fractal = 3;
	set_ratio(&mlx_data);
	start_burning_ship(&mlx_data);
	start_hooks_ship(&mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}

void	complex_plane_dimensions_burning(t_mlx *mlx_data)
{
	mlx_data->real_max = REAL_MAX;
	mlx_data->real_min = REAL_MIN;
	mlx_data->imag_max = COMPLEX_MAX_S;
	mlx_data->imag_min = COMPLEX_MIN_S;
}

int	nb_iterations_burning(t_complex *c, t_complex *z)
{
	int			iterations;
	double		tmp;
	double		module;

	iterations = 0;
	tmp = 0.0;
	module = 0.0;
	while (iterations < NB_ITERATIONS)
	{
		tmp = z->real;
		z->real = (abs_val(z->real) * abs_val(z->real))
			- (abs_val(z->imag) * abs_val(z->imag)) + c->real;
		z->imag = -2 * abs_val(tmp) * abs_val(z->imag) + c->imag ;
		module = get_module(z);
		if (module > VALEUR_MODULE)
			return (iterations);
		iterations++;
	}
	return (iterations);
}
