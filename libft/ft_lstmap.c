/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 03:08:51 by mfroissa          #+#    #+#             */
/*   Updated: 2022/05/16 05:22:23 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nouvlist;

	if (!lst || !f || !del)
		return (NULL);
	nouvlist = 0;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&nouvlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nouvlist, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (nouvlist);
}
