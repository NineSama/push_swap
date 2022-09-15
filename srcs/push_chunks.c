/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:24:43 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 16:25:05 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_util(t_list **sa, t_list **sb, int med, int size)
{
	t_list	*tmp2;

	tmp2 = (*sa)->next;
	push(sa, sb, 'b');
	if (tmp2->index > med && tmp2->index > (med * 2))
	{
		rotate_duo(sa, sb);
		size--;
	}
	else
		rotate(sb, 'b');
}

int	ps(t_list **stack_a, t_list **stack_b, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	int		quantity;

	quantity = 0;
	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		if (tmp->index < mediane)
			ps_util(stack_a, stack_b, mediane, size);
		else if (tmp->index >= mediane && tmp->index < (mediane * 2))
		{
			push(stack_a, stack_b, 'b');
			quantity++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	return (quantity);
}

int	ps_0(t_list **stack_a, t_list **stack_b, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	int		quantity;

	quantity = 0;
	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		if (tmp->index < mediane)
		{
			push(stack_a, stack_b, 'b');
			quantity++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	return (quantity);
}

int	ps_no(t_list **stack_a, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	int		quantity;

	quantity = 0;
	i = 0;
	tmp = *stack_a;
	while (i < size)
	{
		if (tmp->index < mediane)
			quantity++;
		tmp = tmp->next;
		i++;
	}
	return (quantity);
}
