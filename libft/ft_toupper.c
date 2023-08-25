/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:58 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 14:14:58 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*#include <stdio.h>

int main()
{
    char c = 'A';
    printf("%c -> %c\n", c, ft_toupper(c));

    c = 'd';
    printf("%c -> %c\n", c, ft_toupper(c));

    c = '9';
    printf("%c -> %c\n", c, ft_toupper(c));
}*/