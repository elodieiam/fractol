/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractal_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:16:34 by elrichar          #+#    #+#             */
/*   Updated: 2023/08/24 12:19:09 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_arguments(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 11))
		return (2);
	else if (ac == 5 && !ft_strncmp(av[1], "Julia", 6))
	{
		if (check_sign(av[3]) && check_julia_args(av))
			return (3);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "Burning", 8))
		return (4);
	return (1);
}

void	advance_to_dec(char **str, double *result)
{
	while (*(*str) >= '0' && *(*str) <= '9')
	{
		(*result) = (*result) * 10.0 + (*(*str) - '0');
		(*str)++;
	}
}

double	ft_atod(char *str)
{
	double	result;
	double	fraction;
	int		decimal_found;

	result = 0.0;
	fraction = 1.0;
	decimal_found = 0;
	advance_to_dec(&str, &result);
	if (*str == '.')
	{
		decimal_found = 1;
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10.0 + (*str - '0');
			fraction *= 10.0;
			str++;
		}
	}
	if (decimal_found)
		result /= fraction;
	return (result);
}

double	ft_atod_real(char *str)
{
	double	result;
	double	fraction;
	int		decimal_found;
	double	sign;

	result = 0.0;
	fraction = 1.0;
	decimal_found = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= (-1.0);
		str++;
	}
	advance_to_dec(&str, &result);
	if (*str == '.')
	{
		decimal_found = 1;
		str++;
		get_result(&str, &result, &fraction);
	}
	if (decimal_found)
		result /= fraction;
	return (result * sign);
}

void	get_result(char **str, double *result, double *fraction)
{
	while (*(*str) >= '0' && *(*str) <= '9')
	{
		(*result) = (*result) * 10.0 + ((*(*str) - '0'));
		(*fraction) *= 10.0;
		(*str)++;
	}
}
