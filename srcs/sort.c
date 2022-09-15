/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:24:14 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 16:24:36 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	trot(t_list **stack_a, int nb)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (nb == 1)
		return ;
	if (nb == 2)
	{
		if (tmp->content > tmp->next->content)
			swap(stack_a, 'a');
	}
	else
		troi(stack_a);
}

void	troi(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack_a;
	next = tmp->next;
	if (tmp->content > next->content && next->content > next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content > next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else
		troi_2(stack_a, tmp, next);
}

void	troi_2(t_list **stack_a, t_list *tmp, t_list *next)
{
	if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content < next->next->content)
		swap(stack_a, 'a');
	else if (tmp->content < next->content && next->content > next->next->content
		&& tmp->content < next->next->content)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (tmp->content < next->content
		&& next->content > next->next->content)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}

void	only_three(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack_a;
	next = tmp->next;
	if (tmp->content > next->content && next->content > next->next->content)
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content > next->next->content)
		rotate(stack_a, 'a');
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content < next->next->content)
		swap(stack_a, 'a');
	else if (tmp->content < next->content && next->content > next->next->content
		&& tmp->content < next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (tmp->content < next->content
		&& next->content > next->next->content)
		rev_rotate(stack_a, 'a');
}
