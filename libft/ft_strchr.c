/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:46:54 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:46:54 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searched_char)
{
	unsigned char	c;

	c = searched_char;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	const	char *s = "dddddeeeEkkkk";
	int	c = 'E';
	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", strchr(s, c));
}*/
