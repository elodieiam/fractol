/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:56:36 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:56:36 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (str == NULL || to_find == NULL)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && (i + j) < len)
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	const char *l = "foo bar baz";
	const char *s = NULL;
	char *ptr;
	ptr = ft_strnstr(l, s, 18);
    if (ptr == NULL)
        {
            printf("le pointeur est nul\n");
            return (0);
        }
	printf("%s\n", ptr);
	return (0);
}*/