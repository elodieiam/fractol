/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:59:21 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 14:59:21 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*dest_mve;
	const unsigned char	*src_mve;
	int					i;

	if (dest == NULL || src == NULL)
		return (NULL);
	dest_mve = dest;
	src_mve = src;
	if (dest_mve > src_mve)
	{
		i = (int) num - 1;
		while (i >= 0)
		{
			dest_mve[i] = src_mve[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, num);
	return (dest);
}

/*#include <stdio.h>
int main()
{
    char str1[] = "abcde";
    char str2[] = "abcde";

    ft_memmove((str1 + 2),str1,3 );
    ft_memmove((str2 + 2),str2,3 );
    printf("%s\n",str1);
    printf("%s\n",str2);
}*/