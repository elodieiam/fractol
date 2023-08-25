/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:08:22 by elrichar          #+#    #+#             */
/*   Updated: 2023/08/25 18:53:37 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_escape(int keycode, t_mlx *mlx_data)
{
	if (keycode == ESP)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		mlx_destroy_image(mlx_data->mlx, mlx_data->img_data.img);
		mlx_destroy_display(mlx_data->mlx);
		exit(0);
	}
	return (0);
}

int	handle_destroy(t_mlx *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_data.img);
	exit(0);
}

int	mouse_scroll(int event, int x, int y, t_mlx *mlx_data)
{
	if (event == Button4)
		zoom_in(x, y, mlx_data, 0.9);
	else if (event == Button5)
		zoom_out(x, y, mlx_data, 0.9);
	return (0);
}

void	start_hooks_ship(t_mlx *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, ButtonPress, ButtonPressMask,
		mouse_scroll, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, handle_escape, mlx_data);
	mlx_hook(mlx_data->mlx_win, DestroyNotify, 0, handle_destroy, mlx_data);
	mlx_hook(mlx_data->mlx_win, KeyPress, KeyPressMask,
		handle_plane_shift, mlx_data);
}
