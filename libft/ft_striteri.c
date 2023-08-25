/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:48:59 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:48:59 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*int main()
{
    void (*f)(unsigned int, char*);
    f = function;
    ft_striteri("banane",f);
}
void    function(unsigned int i, char* c)
{
    printf("La valeur à l'indice %d est %c\n", i, *c);
}*/