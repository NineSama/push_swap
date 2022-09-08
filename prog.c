/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:04:08 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/08 21:34:37 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	valeur;

	i = 0;
	signe = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	valeur = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		valeur = valeur * 10 + (str[i] - '0');
		i++;
	}
	if (signe % 2 == 1)
		return (valeur * -1);
	return (valeur);
}

void	ft_print(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("C : %d		||	I : %d\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;

	if (!valid(ac, av))
		return (write (1, "Error\n", 6), 0);
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
	if (ac <= 3)
	{
		trot(stack_a, ft_lstsize(stack_a));
		return (0);
	}
	algo(stack_a, stack_b, ac);
	printf("\n A \n");
	ft_print(stack_a);
	printf("\n B \n");
	ft_print(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
