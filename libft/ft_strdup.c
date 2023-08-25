/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:47:49 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:47:49 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*p;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	src_len = i;
	p = malloc((src_len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*int main()
{
	char text1[] = "Elodie";
	printf("%s\n", ft_strdup(text1));
}*/