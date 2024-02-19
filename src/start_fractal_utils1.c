/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractal_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:13:13 by elrichar          #+#    #+#             */
/*   Updated: 2024/02/19 18:22:27 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_ratio(t_mlx *mlx_data)
{
	double	height_win;
	double	width_win;
	double	height_fractal;
	double	width_fractal;

	height_win = WINDOW_Y;
	width_win = WINDOW_X;
	height_fractal = mlx_data->imag_max - mlx_data->imag_min;
	width_fractal = mlx_data->real_max - mlx_data->real_min;
	mlx_data->ratio_x = (width_fractal / width_win);
	mlx_data->ratio_y = (height_fractal / height_win);
}

double	get_module(t_complex *complex_z)
{
	double	x_pow;
	double	y_pow;
	double	module;

	x_pow = (complex_z->real) * (complex_z->real);
	y_pow = (complex_z->imag) * (complex_z->imag);
	module = sqrt(x_pow + y_pow);
	return (module);
}

int	get_iterations(int x, int y, t_mlx *mlx_data)
{
	t_complex	complex_c;
	t_complex	complex_z;
	int			iterations;

	complex_c.real = mlx_data->real_min + x * (mlx_data->ratio_x);
	complex_c.imag = mlx_data->imag_max - (y - 35) * (mlx_data->ratio_x);
	complex_z.real = 0.0;
	complex_z.imag = 0.0;
	iterations = nb_iterations(&complex_c, &complex_z);
	return (iterations);
}

int	nb_iterations(t_complex *complex_c, t_complex *complex_z)
{
	int		iterations;
	double	tmp;
	double	module;

	iterations = 0;
	tmp = 0.0;
	module = 0.0;
	while (iterations < NB_ITERATIONS)
	{
		tmp = complex_z->real;
		complex_z->real = (complex_z->real * complex_z->real)
			- (complex_z->imag * complex_z->imag) + complex_c->real;
		complex_z->imag = 2 * tmp * complex_z->imag + complex_c->imag;
		module = get_module(complex_z);
		if (module > VALEUR_MODULE)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

void	complex_plane_dimensions(t_mlx *mlx_data)
{
	mlx_data->real_max = REAL_MAX;
	mlx_data->real_min = REAL_MIN;
	mlx_data->imag_max = COMPLEX_MAX;
	mlx_data->imag_min = COMPLEX_MIN;
}
