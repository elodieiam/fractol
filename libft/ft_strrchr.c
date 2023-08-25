/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:00:45 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 15:00:45 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searched_char)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = searched_char;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	const   char *s = "tripouille";
	printf("%p et %s\n", s, ft_strrchr(s,'v'));
}*/