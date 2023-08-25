/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:10:02 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 14:10:02 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_el, size_t size)
{
	void	*arr;
	size_t	total_size;

	total_size = nb_el * size;
	if (size != 0 && (total_size / size != nb_el))
		return (NULL);
	arr = malloc(total_size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, total_size);
	return (arr);
}

/*#include <stdio.h>
int	main(void)
{
	int	*tab;
	tab = ft_calloc(0, 4);
	printf("%p\n", tab);
	free(tab);
	return (0);
}*/