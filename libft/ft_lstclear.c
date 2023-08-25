/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:20:20 by elrichar          #+#    #+#             */
/*   Updated: 2023/05/07 16:14:27 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (lst && (*del))
	{
		p = *lst;
		while (p)
		{
			p = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = p;
		}
	*lst = NULL;
	}
}
