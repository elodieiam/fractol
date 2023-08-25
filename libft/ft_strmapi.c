/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:54:42 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:54:42 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapi;
	unsigned int	len;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	mapi = malloc((len + 1) * sizeof(char));
	if (mapi == NULL)
		return (NULL);
	while (i < len)
	{
		mapi[i] = (*f)(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}

/*#include <stdio.h>

int main()
{
    char    *s = "banane";
    printf("%s\n",ft_strmapi(s, &function));
    printf("%s\n", s);
	char    function(unsigned int i, char c)
{
    c = c + i;
    return (c);
}
}*/