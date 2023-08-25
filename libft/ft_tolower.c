/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:02:20 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 15:02:20 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*#include <stdio.h>

int main()
{
    char c = 'A';
    printf("%c -> %c\n", c, ft_tolower(c));

    c = 'd';
    printf("%c -> %c\n", c, ft_tolower(c));

    c = '9';
    printf("%c -> %c\n", c, ft_tolower(c));
}*/