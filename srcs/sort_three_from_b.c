/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_from_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:26:02 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 16:26:21 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_from_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack_b;
	next = tmp->next;
	if (tmp->content < next->content && next->content < next->next->content)
	{
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content > next->next->content)
	{
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else
		s_3fb2(stack_a, stack_b, tmp, next);
}

void	s_3fb2(t_list **stack_a, t_list **stack_b, t_list *tmp, t_list *next)
{
	if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content < next->next->content)
	{
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else if (tmp->content < next->content && next->content > next->next->content
		&& tmp->content < next->next->content)
	{
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else
		s_3fb3(stack_a, stack_b, tmp, next);
}

void	s_3fb3(t_list **stack_a, t_list **stack_b, t_list *tmp, t_list *next)
{
	if (tmp->content < next->content
		&& next->content > next->next->content)
	{
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else
	{
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
}
