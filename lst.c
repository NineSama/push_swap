/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:31:52 by mfroissa          #+#    #+#             */
/*   Updated: 2022/08/29 19:15:39 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	printf("%d\n", new->content);
	return (new);
}

void	ft_lstadd_back(t_list **lst, int content)
{
	t_list	*tmp;
	t_list	*new;

	new = ft_lstnew(content);
	if (!lst || !new)
		return ;
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
