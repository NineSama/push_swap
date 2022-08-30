/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:47:04 by mfroissa          #+#    #+#             */
/*   Updated: 2022/08/30 21:01:07 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stacka, char c)
{
	int		i;
	t_list	*tmp;

	i = (*stacka)->content;
	tmp = (*stacka)->next;
	(*stacka)->content = tmp->content;
	tmp->content = i;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push(t_list **stack_1, t_list **stack_2, char c)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;
	
	tmp = *stack_1;
	tmp1 = *stack_1;
	tmp1 = tmp1->next;
	(*stack_1) = tmp1;
	if (!(*stack_2))
	{
		*stack_2 = tmp;
		(*stack_2)->next = NULL;
	}
	else
	{
		tmp2 = *stack_2;
		*stack_2 = tmp;
		(*stack_2)->next = tmp2;
	}
	if (c == 'a')
		write (1, "pa\n", 3);
	else
		write (1, "pb\n", 3);
}
