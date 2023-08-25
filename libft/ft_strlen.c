/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:54:26 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:54:26 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*
#include <stdio.h>

int main()
{
    char str1[] = "c'est pas evident";
    char str2[] = "de comprendre la compilation";

    printf("%d et %d\n", ft_strlen(str1), ft_strlen(str2));
}
*/