/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:36:57 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/07 20:02:56 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_tab(int	*tab, t_list **stack, int nb)
{
	int		i;
	t_list	*tmp;

	tab = malloc(sizeof(int) * nb);
	tmp = *stack;
	i = 0;
	while (i < nb)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_sort_tab(tab, nb);
	return (tab);
}

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	put_index(int *tab, t_list **stack, int ac)
{
	int		i;
	t_list	*tmp;
	t_list	*first;

	i = 0;
	first = *stack;
	while (i < ac)
	{
		tmp = first;
		while (tmp->content != tab[i])
			tmp = tmp->next;
		if (tmp->content == tab[i])
			tmp->index = i;
		i++;
	}
}

int	get_mediane(int *tab, t_list **stack, int nb)
{
	int		mediane;
	t_list	*tmp;

	tmp = *stack;
	while (tmp->content != tab[(nb / 2)])
		tmp = tmp->next;
	mediane = tmp->index;
	return (mediane);
}
