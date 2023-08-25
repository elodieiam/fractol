/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:55:36 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:55:36 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[i] == s2[i] && s1[i] && i < len - 1)
		i++;
	if (len < 1)
		return (0);
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
        unsigned int    n = 4;
        char    s1[] = "dedDe";
        char    s2[] = "dedse";
        printf("%d\n", strncmp(s1, s2, n));
        printf("%d\n",ft_strncmp(s1, s2, n));
        printf("%d\n", strncmp(s1, s2, n));
	return (0);
}*/