/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:01:38 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 15:01:38 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start_len(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s1[i] && ft_is_set(set, s1[i]))
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_end_len(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = ft_strlen(s1) - 1;
	len = 0;
	while (i >= 0 && ft_is_set(set, s1[i]))
	{
		len++;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	len_start;
	size_t	len_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_start = 0;
	len_end = 0;
	if (ft_start_len(s1, set))
		len_start = ft_start_len(s1, set);
	if (ft_end_len(s1, set))
		len_end = ft_end_len(s1, set);
	arr = ft_substr(s1, len_start, (ft_strlen(s1) - (len_start + len_end)));
	return (arr);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strtrim("banane orange banane", "banane"));
	return (0);
}*/
