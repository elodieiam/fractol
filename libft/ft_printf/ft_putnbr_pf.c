/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:57:24 by elrichar          #+#    #+#             */
/*   Updated: 2023/07/22 14:08:09 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_ilen(long nb)
{
	long int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= (-1);
	}
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_pf(int n)
{
	long int	nb;
	char		c;
	int			len_el;

	nb = n;
	len_el = ft_ilen(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 0 && nb < 10)
	{
		c = nb + 48;
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr_pf((nb / 10));
		ft_putnbr_pf((nb % 10));
	}
	return (len_el);
}
