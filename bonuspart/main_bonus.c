/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:24:13 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 22:33:04 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2 || !av[1][0])
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
	checker_core(stack_a, stack_b);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
