/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:01:45 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/22 14:07:22 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_element(const char *s, va_list args)
{
	int				len_el;
	unsigned long	add;

	len_el = 0;
	if (*s == '%')
		len_el = ft_putchar_pf('%');
	else if (*s == 'c')
		len_el = ft_putchar_pf(va_arg(args, int));
	else if (*s == 's')
		len_el = ft_putstr_pf(va_arg(args, char *));
	else if (*s == 'X' || *s == 'x')
		len_el = ft_puthex(va_arg(args, unsigned int), *s);
	else if (*s == 'i' || *s == 'd')
		len_el = ft_putnbr_pf(va_arg(args, int));
	else if (*s == 'u')
		len_el = ft_putunbr(va_arg(args, unsigned int));
	else if (*s == 'p')
	{
		add = va_arg(args, unsigned long);
		if (add != 0)
			len_el = ft_putstr_pf("0x");
		len_el += ft_putaddr(add);
	}
	return (len_el);
}
