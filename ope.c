/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:04:08 by mfroissa          #+#    #+#             */
/*   Updated: 2022/06/30 22:29:49 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	sa(t_list *list, char *name)
{
	t_list	*tmp;
	t_lists	**stack;

	if (name[1] == 'a')
		list = stack->listA;
	else
		list = stack->listB;
	tmp = list;
	list = list->next;
	list->next = tmp;
	if (name[1] == 'a')
		write (1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}
*/

t_list	*init_list(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		write(1, "Error\n", 6);
	new->content = content;
	new->next = NULL;
	return (new);
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
	t_list	*new;
	
	new = init_list(ft_atoi(av[1]));
	printf("%d\n", new->content);
	i = 2;
	while (i < ac)
	{
		new->next = init_list(ft_atoi(av[i]));
		printf("%d\n", new->content);
		i++;
	}
	return (0);
}
