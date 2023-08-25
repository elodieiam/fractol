/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:38:41 by elrichar          #+#    #+#             */
/*   Updated: 2023/08/23 15:32:42 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int	check;

	check = check_arguments(ac, av);
	if (check == 2)
		set_mandelbrot_vars();
	else if (check == 3)
		set_julia_vars(av);
	else if (check == 4)
		set_burning_fractal_vars();
	else
	{
		print_instructions();
		exit (1);
	}
}
