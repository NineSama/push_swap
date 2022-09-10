/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:34:53 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/09 21:58:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	from_b_to_a_last(t_list **stack_a, t_list **stack_b, int nb, int mediane)
{
	int	i;
	int pa;
	t_list	*tmp;

	i = 0;
	pa = 0;
	tmp = *stack_b;
	while (i < nb)
	{
		tmp = *stack_b;
		if (tmp->index > mediane)
		{
			push(stack_b, stack_a, 'a');
			pa++;
		}
		else
			rotate(stack_b, 'b');
		i++;
	}
	return (pa);
}

void	tri_last_chunk(t_list **stack_a, t_list **stack_b, int nb)
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
	pa = from_b_to_a_last(stack_a, stack_b, nb, mediane);
	truc(stack_a, stack_b, pa);
	tri_last_chunk(stack_a, stack_b, nb - pa);
	free(tab);
}
