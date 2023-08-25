/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:42 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 14:43:42 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_strings(char const *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			nb++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (nb);
}

static int	len_word(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	*free_mem(char **strings, int i)
{
	while (i--)
	{
		if (strings[i])
			free(strings[i]);
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		wd_len;

	i = 0;
	strings = malloc(sizeof(char *) * (nb_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			wd_len = len_word(s, c);
			strings[i] = ft_calloc(wd_len + 1, sizeof(char));
			if (!strings[i])
				return (free_mem(strings, i));
			ft_strlcpy(strings[i], s, wd_len + 1);
			s += wd_len;
			i++;
		}
	}
	strings[i] = NULL;
	return (strings);
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	(void)	argc;
	split = ft_split(argv[1], ' ');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}*/