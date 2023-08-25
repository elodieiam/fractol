/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elodie <elodie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:18 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/06 14:59:50 by elodie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memBlock, int searchedChar, size_t size)
{
	const unsigned char	*p;
	unsigned char		c;

	p = memBlock;
	c = searchedChar;
	while (size > 0)
	{
		if (*p == c)
			return ((void *)p);
		p++;
		size--;
	}
	return (NULL);
}
