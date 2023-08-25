/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:54:58 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 14:54:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pnt1, const void *pnt2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)pnt1;
	p2 = (unsigned char *)pnt2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

/*#include <stdio.h>
int main() {

    int array1 [] = { 54, 85, 20, 63, 21 };
    int array2 [] = { 54, 85, 19, 63, 21 };
    size_t size = sizeof( int ) * 5;

    assert( memcmp( array1, array2, size) == 
	ft_memcmp( array1, array2, size) );       
    assert( memcmp( array1, array1, size) == 
	ft_memcmp( array1, array1, size) );       
    assert( memcmp( array2, array1, size) == 
	ft_memcmp( array2, array1, size) );       
    
    printf( "Test is ok\n" ); 
    const char	*s1 = "sdsfds";
	const char	*s2 = "sddgdtre";
	
	printf("%d\n", memcmp((const void *)s1, (const void *)s2, 5));
        printf("%d\n", ft_memcmp((const void *)s1, (const void *)s2, 5));
    
    return 0;
}*/