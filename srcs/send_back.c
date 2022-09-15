/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:25:40 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 16:25:56 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	send_back(t_list **stack_a, t_list **stack_b, t_list **number)
{
	t_list	*tmp;

	tmp = *number;
	while (tmp && *stack_b)
	{
		if (!tmp->next)
		{
			if (*stack_b)
				tri_last_chunk(stack_a, stack_b, tmp->content);
			return ;
		}
		tri(stack_a, stack_b, tmp->content);
		tmp = tmp->next;
	}
}

void	tri(t_list **stack_a, t_list **stack_b, int nb)
{
	int		*tab;
	int		mediane;
	int		pa;

	if (nb < 4)
	{
		three_or_two(stack_a, stack_b, nb);
		return ;
	}
	tab = NULL;
	tab = create_tab(tab, stack_b, nb);
	mediane = get_mediane(tab, stack_b, nb);
	pa = from_b_to_a(stack_a, stack_b, nb, mediane);
	truc(stack_a, stack_b, pa);
	tri(stack_a, stack_b, nb - pa);
	free(tab);
}

t_list	*truc_util(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list	*tmp;
	t_list	*result;
	int		i;
	int		med;
	int		*tab;

	tab = NULL;
	tab = create_tab(tab, stack_a, nb);
	med = get_mediane(tab, stack_a, nb);
	i = 0;
	result = ft_lstnew(0);
	result->index = 0;
	while (i < nb && result->content != nb / 2 + 1)
	{
		tmp = *stack_a;
		if (tmp->index <= med)
		{
			push(stack_a, stack_b, 'b');
			result->content++;
		}
		else if (result->index++ >= 0)
			rotate(stack_a, 'a');
		i++;
	}
	return (free(tab), result);
}

void	truc(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list	*result;

	if (nb <= 3)
		trot(stack_a, nb);
	else
	{
		result = truc_util(stack_a, stack_b, nb);
		rev_b_to_a(stack_a, result->index, 'a');
		truc(stack_a, stack_b, nb - result->content);
		tri(stack_a, stack_b, result->content);
		free(result);
	}
}
