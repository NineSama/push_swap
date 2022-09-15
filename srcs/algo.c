/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:42:29 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 22:08:47 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_count_0(t_list **sa, t_list **sb, int ac, t_list **number)
{
	int	*tab;
	int	m;

	tab = NULL;
	tab = create_tab(tab, sa, ft_lstsize(sa));
	if (ft_lstsize(sa) == ac - 1)
		put_index(tab, sa, ft_lstsize(sa));
	m = get_mediane(tab, sa, ft_lstsize(sa));
	if (ac != 6)
	{
		m = get_mediane_tiers(tab, sa, ft_lstsize(sa));
		ft_la_f(number, ps_no(sa, ft_lstsize(sa), m));
		ft_la_f(number, ps(sa, sb, ft_lstsize(sa), m));
	}
	free(tab);
}

void	algo_count(t_list **sa, t_list **sb, t_list **number)
{
	int	*tab;
	int	m;

	tab = NULL;
	tab = create_tab(tab, sa, ft_lstsize(sa));
	m = get_mediane(tab, sa, ft_lstsize(sa));
	ft_la_f(number, ps_0(sa, sb, ft_lstsize(sa), m));
	free(tab);
}

void	algo(t_list **stack_a, t_list **stack_b, int ac)
{
	t_list	**number;
	int		count;

	count = 0;
	number = malloc(sizeof(t_list));
	*number = NULL;
	while (ft_lstsize(stack_a) > 3)
	{
		if (count == 0)
			algo_count_0(stack_a, stack_b, ac, number);
		if (count != 0)
			algo_count(stack_a, stack_b, number);
		count++;
	}
	if (ft_lstsize(stack_a) == 2)
		trot(stack_a, 2);
	else if (ft_lstsize(stack_a) == 3)
		only_three(stack_a);
	send_back(stack_a, stack_b, number);
	ft_free_list(number);
}
