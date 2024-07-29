/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:38:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/07/29 21:10:26 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	start_fractal(int check, char **av)
{
	if (check == 2)
	{
		if (set_mandelbrot_vars())
			return (ft_putstr_fd("Minilibx error\n", 2), 1);
	}
	else if (check == 3)
	{
		if (set_julia_vars(av))
			return (ft_putstr_fd("Minilibx error\n", 2), 1);
	}
	else if (check == 4)
	{
		if (set_burning_fractal_vars())
			return (ft_putstr_fd("Minilibx error\n", 2), 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	check;

	check = check_arguments(ac, av);
	if (check == 2 || check == 3 || check == 4)
	{
		if (start_fractal(check, av))
			return (1);
	}
	else
		return (print_instructions(), 1);
}
