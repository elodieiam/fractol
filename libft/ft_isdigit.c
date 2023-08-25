/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:49:42 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 11:49:48 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
    char c = '8';
    char d = 'A';
    char e = '0';

    printf("%d, %d et %d\n", ft_isdigit(c), ft_isdigit(d), ft_isdigit(e));
}
*/
