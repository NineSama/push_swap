/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:23:47 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 16:24:05 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_b_to_a(t_list **stack, int rotatee, char c)
{
	int	i;

	i = 0;
	if (c == 'b')
	{
		while (i < rotatee)
		{
			rev_rotate(stack, 'b');
			i++;
		}
	}
	else
	{
		while (i < rotatee)
		{
			rev_rotate(stack, 'a');
			i++;
		}
	}
}

int	from_b_to_a(t_list **stack_a, t_list **stack_b, int nb, int mediane)
{
	int		i;
	int		pa;
	t_list	*tmp;
	int		rotatee;

	i = 0;
	pa = 0;
	tmp = *stack_b;
	rotatee = 0;
	while (i < nb && pa != nb / 2)
	{
		tmp = *stack_b;
		if (tmp->index > mediane)
		{
			push(stack_b, stack_a, 'a');
			pa++;
		}
		else if (rotatee++ >= 0)
			rotate(stack_b, 'b');
		i++;
	}
	rev_b_to_a(stack_b, rotatee, 'b');
	return (pa);
}

void	three_or_two(t_list **stack_a, t_list **stack_b, int nb)
{
	if (nb == 1)
		push(stack_b, stack_a, 'a');
	else if (nb == 2)
	{
		trot(stack_a, 2);
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
		trot(stack_a, 2);
	}
	else
		sort_three_from_b(stack_a, stack_b);
}
