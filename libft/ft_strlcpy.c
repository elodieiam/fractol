/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:52:14 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:52:14 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (l);
}

/*#include <stdio.h>

int main()
{
    char dest[] = "sebastien";
    char src[] = "ffff";

    printf("%s et %d\n", dest, ft_strlcpy(dest, src, 3));
}*/