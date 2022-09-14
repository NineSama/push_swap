/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:57:49 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/09 21:59:36 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_checksort(t_list **stack)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack;
	while (tmp->next)
	{
		next = tmp->next;
		if (tmp->content > next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

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
				printf("checkdup");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_checknum(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("checknum");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_checkint(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
		{
			printf("checkint");
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid(int ac, char **av)
{
	if (!ft_checkint(ac, av))
		return (0);
	if (!ft_checkdup(ac, av))
		return (0);
	if (!ft_checknum(ac, av))
		return (0);
	return (1);
}
