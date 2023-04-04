/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:35:06 by vfaramel          #+#    #+#             */
/*   Updated: 2023/01/27 05:54:46 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*i;
	t_list	**start;

	if (!lst || !f || !del)
		return (0);
	node = ft_lstnew(f(lst->content));
	i = node;
	start = &i;
	while (lst->next)
	{
		lst = lst->next;
		node = ft_lstnew(f(lst->content));
		ft_lstadd_back(start, node);
	}
	return (*start);
}
