/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:03:40 by mfroissa          #+#    #+#             */
/*   Updated: 2022/06/27 04:52:48 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	if (!list)
		return (0);
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	**start;
	t_list	*m1;
	t_list	*m2;
	t_list	*m3;
	t_list	*m4;

	start = &m1;
	m1 = ft_lstnew("M");
	m2 = ft_lstnew("A");
	m3 = ft_lstnew("T");
	m4 = ft_lstnew("!");
	m1->next = m2;
	m2->next = m3;
	m3->next = m4;
	printf("%d\n", ft_lstsize(&start));
	return (0);
}*/
