/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:47:04 by mfroissa          #+#    #+#             */
/*   Updated: 2022/08/29 20:51:08 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stacka, char c)
{
	int		i;
	t_list	*tmp;

	i = stacka->content;
	tmp = stacka->next;
	stacka->content = tmp->content;
	stacka = stacka->next;
	stacka->content = i;
	if (c == 'a')
		write(1, "sa\n", 3);
	else	
		write(1, "sb\n", 3);
}
/*
void	ss(int a; int b)
{
}

void	pa(int a; int b)
{
}

void	pb(int a; int b)
{
}

void	ra(int a; int b)
{
}

void	rb(int a; int b)
{
}

void	rr(int a; int b)
{
}

void	rra(int a; int b)
{
}

void	rrb(int a; int b)
{
}

void	rrr(int a; int b)
{
}
*/
