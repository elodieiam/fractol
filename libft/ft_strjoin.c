/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:49:52 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:49:52 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	arr = malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		arr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		arr[i] = *s2;
		i++;
		s2++;
	}
	arr[i] = '\0';
	return (arr);
}

/*#include <stdio.h>

int main()
{
    char s1[] = "";
    char s2[] = "";
    char *s3 = ft_strjoin(s1,s2);
    printf("%s\n", s3);
}*/