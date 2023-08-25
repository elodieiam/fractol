/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:01:57 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/03 15:01:57 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		start = slen;
	if (len > slen - start)
		len = slen - start;
	tab = ft_calloc(len + 1, sizeof(char));
	if (tab == NULL)
		return (NULL);
	ft_memcpy(tab, (s + start), len);
	return (tab);
}
