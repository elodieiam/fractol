/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:28:45 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 14:28:45 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
    char a = 'A';
    char c = 72;
    char d = '!';

    printf("%d, %d et %d\n", ft_isprint(a), ft_isprint(c), ft_isprint(d));
} */