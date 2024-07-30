/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:16:05 by elrichar          #+#    #+#             */
/*   Updated: 2024/07/30 18:41:37 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_complex(char *s)
{
	if ((*s < '0' || *s > '9') || !*s)
		return (0);
	if (*s == '0' && *(s + 1) == 'i')
		return (0);
	while (*s && *s != '.' && *s != 'i')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	if (*s == '.')
	{
		s++;
		if (!*s)
			return (0);
		while (*s && *s != 'i')
		{
			if (*s < '0' || *s++ > '9')
				return (0);
		}
	}
	if (*s != 'i' || (*s == 'i' && *(s + 1)))
		return (0);
	return (1);
}

int	check_sign_julia(char *s)
{
	if ((*s < '0' || *s > '9') && (*s != '+' && *s != '-'))
		return (0);
	else if (*s == '+' || *s == '-')
	{
		s++;
		if ((*s == '0' && !*(s + 1)) || !*s)
			return (0);
		else if (*s < '0' || *s > '9')
			return (0);
	}
	return (1);
}

int	is_real(char *s)
{
	if (!*s)
		return (0);
	if (!check_sign_julia(s))
		return (0);
	s++;
	while (*s && *s != '.')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	if (*s == '.')
	{
		s++;
		if (!*s)
			return (0);
		while (*s)
		{
			if (*s < '0' || *s > '9')
				return (0);
			s++;
		}
	}
	return (1);
}

int	check_julia_args(char **av)
{
	if (!is_real(av[2]))
		return (0);
	if (!is_complex(av[4]))
		return (0);
	return (1);
}

void	print_instructions(void)
{
	ft_printf("\033[1mTo display the fractal:\033[0m\n\n");
	ft_printf("\033[1;35mMandelbrot:\033[0m ./fractol Mandelbrot\n\n");
	ft_printf("\033[1;35mJulia:\033[0m   ./fractol Julia + complex number\n");
	ft_printf("Example: ./fractol Julia 0.355 + 0.355i\n");
	ft_printf("         ./fractol Julia -0.54 + 0.54i\n");
	ft_printf("         ./fractol Julia  0 + 0.8i\n\n");
	ft_printf("\033[1;35mBurning Ship:\033[0m ./fractol Burning\n\n");
	ft_printf("Have fun !\n");
}
