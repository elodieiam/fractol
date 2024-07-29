/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:57:25 by elrichar          #+#    #+#             */
/*   Updated: 2024/07/29 22:33:38 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//penser à vérifier si les paramètres sont dans la limite des double
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>

//define plane dimensions, nb of iterations and module
# define WINDOW_X 1000
# define WINDOW_Y 600
# define WINDOW_Y_S 800
# define WINDOW_X_S 800
# define REAL_MAX 2
# define REAL_MIN -2
# define COMPLEX_MAX 1
# define COMPLEX_MIN -1
# define COMPLEX_MAX_S 2
# define COMPLEX_MIN_S -2
# define VALEUR_MODULE 4
# define NB_ITERATIONS 150

//define colors
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFA07A
# define COLOR_CYAN 0x15EFE5
# define COLOR_MAGENTA 0xD03EC6
# define COLOR_ORANGE 0xD35400
# define COLOR_BLACK 0x000000

//define key codes
# define ESP 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

//structures
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	double		ratio_x;
	double		ratio_y;
	double		real_min;
	double		real_max;
	double		imag_min;
	double		imag_max;
	t_img		img_data;
	t_complex	complex;
	double		indicator;
	int			fractal;
	int 		color;
}	t_mlx;

//burning.c
int		get_iterations_ship(int x, int y, t_mlx *mlx_data);
void	start_burning_ship(t_mlx *mlx_data);
int		set_burning_fractal_vars(void);
void	complex_plane_dimensions_burning(t_mlx *mlx_data);
int		nb_iterations_burning(t_complex *c, t_complex *z);

//check_arguments_utils.c
int		is_complex(char *s);
int		check_sign_julia(char *s);
int		is_real(char *s);
int		check_julia_args(char **av);
void	print_instructions(void);

//color_push_pixel.c
void	push_pixel(int x, int y, t_mlx *mlx_data, int color);
void	color_pixel_julia(int x, int y, int iterations, t_mlx *mlx_data);
void	color_pixel_zoom(int x, int y, double iterations, t_mlx *mlx_data);
void	color_pixel(int x, int y, double iterations, t_mlx *mlx_data);
void	color_pixel_burning(int x, int y, double iterations, t_mlx *mlx_data);

//julia.c
void	start_julia(t_mlx *mlx_data);
int		set_julia_vars(char **av);
void	start_hooks_julia(t_mlx *mlx_data);
int		nb_iterations_julia(t_complex *c, t_complex *z, double i);
int		get_iterations_julia(int x, int y, t_mlx *mlx_data);

//mandelbrot.c
void	start_mandelbrot(t_mlx *mlx_data, int indicator);
int		set_mandelbrot_vars(void);
int		check_sign(char *s);
int		abs_val(int x);

//mlx_hook.c
int		handle_escape(int keycode, t_mlx *mlx_data);
int		handle_destroy(t_mlx *mlx_data);
int		mouse_scroll(int event, int x, int y, t_mlx *mlx_data);
void	start_hooks_ship(t_mlx *mlx_data);

//start_fractal_utils1.c
void	set_ratio(t_mlx *mlx_data);
double	get_module(t_complex *complex_z);
int		get_iterations(int x, int y, t_mlx *mlx_data);
int		nb_iterations(t_complex *complex_c, t_complex *complex_z);
void	complex_plane_dimensions(t_mlx *mlx_data);

//start_fractal_utils2.c
int		check_arguments(int ac, char **av);
void	advance_to_dec(char **str, double *result);
double	ft_atod(char *str);
double	ft_atod_real(char *str);
void	get_result(char **str, double *result, double *fraction);

//zoom_plane.c
void	zoom_in(int x, int y, t_mlx *mlx_data, double zoom);
void	zoom_out(int x, int y, t_mlx *mlx_data, double zoom);

//shift_plane.c
int		handle_plane_shift(int keycode, t_mlx *mlx_data);
void	move_plane_up(t_mlx *mlx_data);
void	move_plane_down(t_mlx *mlx_data);
void	move_plane_right(t_mlx *mlx_data);
void	move_plane_left(t_mlx *mlx_data);

#endif