/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:24:51 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/02 14:24:51 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
    char c = 'A';
    int A = 45;
    int B = 12;
    int C = 74;

    printf("%d, %d et %d\n", isalnum(A), isalnum(B), isalnum(C));
}

renvoie 1 si alphanumérique sinon 0 
alphanumérique : 48 et 57 pour les chiffres 
65 et 90 pour les majuscules 
97 à 122 pour les minuscules */ 