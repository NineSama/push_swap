/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:31:52 by mfroissa          #+#    #+#             */
/*   Updated: 2022/08/30 20:09:40 by mfroissa         ###   ########.fr       */
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
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstlast(t_list **lst)
{
	if (!(*lst))
		return (NULL);
	while ((*lst)->next)
		*lst = (*lst)->next;
	return (*lst);
}
/*
int	ft_lstsize(t_list *stack)
{
	int	i;
	t_list	*stack;

	lst = stack
	if (!lst)
		return ();
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstdel(t_list *lst, int i)
{
	while (lst
}*/
