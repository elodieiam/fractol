/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:11:03 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/25 14:14:18 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_julia(t_mlx *mlx_data)
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
			iterations = get_iterations_julia(x, y, mlx_data);
			color_pixel_julia(x, y, iterations, mlx_data);
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
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WINDOW_X, WINDOW_Y,
			"Julia Fractal");
	if (!mlx_data->mlx_win)
		return (1);
	mlx_data->img_data.img = mlx_new_image(mlx_data->mlx, WINDOW_X, WINDOW_Y);
	if (!mlx_data->img_data.img)
		return (1);
	return (0);
}

int	set_julia_vars(char **av)
{
	t_mlx	mlx_data;

	ft_bzero(&mlx_data, sizeof(mlx_data));
	if (*av[3] == '+')
		mlx_data.indicator = 1;
	else if (*av[3] == '-')
		mlx_data.indicator = -1;
	mlx_data.complex.real = ft_atod_real(av[2]);
	mlx_data.complex.imag = ft_atod(av[4]);
	if (init_minilibx(&mlx_data))
		return (1);
	mlx_data.img_data.addr = mlx_get_data_addr(mlx_data.img_data.img,
			&mlx_data.img_data.bpp, &mlx_data.img_data.line_length,
			&mlx_data.img_data.endian);
	mlx_data.fractal = 2;
	complex_plane_dimensions(&mlx_data);
	set_ratio(&mlx_data);
	start_julia(&mlx_data);
	start_hooks_julia(&mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}

void	start_hooks_julia(t_mlx *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, ButtonPress, ButtonPressMask,
		mouse_scroll, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, handle_escape, mlx_data);
	mlx_hook(mlx_data->mlx_win, DestroyNotify, 0, handle_destroy, mlx_data);
	mlx_hook(mlx_data->mlx_win, KeyPress, KeyPressMask,
		handle_plane_shift, mlx_data);
}

int	nb_iterations_julia(t_complex *c, t_complex *z, double indicator)
{
	int		iterations;
	double	tmp;
	double	module;

	iterations = 0;
	tmp = 0.0;
	module = 0.0;
	while (iterations < NB_ITERATIONS)
	{
		tmp = c->real;
		c->real = (c->real * c->real) - (c->imag * c->imag) + z->real;
		c->imag = 2 * tmp * c->imag + (indicator * (z->imag));
		module = get_module(c);
		if (module > VALEUR_MODULE)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

int	get_iterations_julia(int x, int y, t_mlx *mlx_data)
{
	t_complex	complex_c;
	t_complex	z;
	int			iterations;
	double		indicator;

	z = mlx_data->complex;
	indicator = mlx_data->indicator;
	complex_c.real = mlx_data->real_min + x * mlx_data->ratio_x;
	complex_c.imag = mlx_data->imag_max - y * mlx_data->ratio_x;
	iterations = nb_iterations_julia(&complex_c, &z, indicator);
	return (iterations);
}
