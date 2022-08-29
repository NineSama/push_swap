/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:04:08 by mfroissa          #+#    #+#             */
/*   Updated: 2022/08/29 20:50:44 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkdup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				printf("Il y a un dup\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	printf("Pas de dup\n");
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	valeur;

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

int	main(int ac, char **av)
{
	int		i;
	t_list	*stacka;

	ft_checkdup(ac, av);
	stacka = ft_lstnew(ft_atoi(av[1]));
	i = 2;
	while (i < ac)
	{
		ft_lstadd_back(&stacka, ft_atoi(av[i]));
		i++;
	}
	sa(stacka, 'b');
	while (stacka->next)
	{
		printf("%d\n", stacka->content);
		stacka = stacka->next;
	}
	printf("%d\n", stacka->content);
	return (0);
}
