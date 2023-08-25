/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:03:41 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 11:03:41 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	unsigned char	*p;

	p = pointer;
	while (size > 0)
	{
		*p = value;
		size--;
		p++;
	}
	return (pointer);
}

/*#include <stdio.h>

int main ()
{
	char str[] = "Bonjour Elodiiiie";
	ft_memset(str,32,4 *sizeof(char));
	printf("%s\n",str);
}*/
