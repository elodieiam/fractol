/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:37:36 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/22 14:08:44 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_pf(char *s)
{
	int	len_el;

	len_el = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		len_el += ft_putchar_pf(*s);
		s++;
	}
	return (len_el);
}

int	ft_putchar_pf(char c)
{
	write (1, &c, 1);
	return (1);
}
