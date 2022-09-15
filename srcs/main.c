/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:22:44 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 22:34:01 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (1);
	if (!valid(ac, av))
		return (write (1, "Error\n", 6), 1);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack_a, ft_atoi(av[i]));
		i++;
	}
	if (ft_checksort(stack_a))
		return (ft_free_list(stack_a), free(stack_b), 1);
	algo(stack_a, stack_b, ac);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
