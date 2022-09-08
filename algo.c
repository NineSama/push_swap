/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:42:29 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/09 00:02:45 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_chunks(t_list **stack_a, t_list **stack_b, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	int		quantity;

	i = 0;
	quantity = 0;
	while (i < size)
	{
		tmp = *stack_a;
		if (tmp->index < mediane)
		{
			push(stack_a, stack_b, 'b');
			quantity++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	return (quantity);
}

void	algo(t_list **stack_a, t_list **stack_b, int ac)
{
	int		*tab;
	int		mediane;
	t_list	**number;

	number = malloc(sizeof(t_list));
	*number = NULL;
	while (ft_lstsize(stack_a) > 3)
	{
		tab = NULL;
		tab = create_tab(tab, stack_a, ft_lstsize(stack_a));
		if (ft_lstsize(stack_a) == ac - 1)
			put_index(tab, stack_a, ft_lstsize(stack_a));
		mediane = get_mediane(tab, stack_a, ft_lstsize(stack_a));
		ft_lstadd_front(number, push_chunks(stack_a, stack_b, ft_lstsize(stack_a), mediane));
		free(tab);
	}
	trot(stack_a, ft_lstsize(stack_a));
	send_back(stack_a, stack_b, number);
}

void	send_back(t_list **stack_a, t_list **stack_b, t_list **number)
{
	t_list	*tmp;

	tmp = *number;
	while (tmp)
	{
		if (!tmp->next)
		{
			tri_last_chunk(stack_a, stack_b, tmp->content);
			return ;
		}
		tri(stack_a, stack_b, tmp->content);
		tmp = tmp->next;
	}
	free(number);
}

void	sort_three_from_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack_b;
	next = tmp->next;
	if (tmp->content < next->content && next->content < next->next->content)
	{
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content > next->next->content)
	{
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else
		sort_three_from_b_two(stack_a, stack_b, tmp, next);
}

void	sort_three_from_b_two(t_list **stack_a, t_list **stack_b, t_list *tmp, t_list *next)
{
	if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content < next->next->content)
	{
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else if (tmp->content < next->content && next->content > next->next->content
		&& tmp->content < next->next->content)
	{
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
	else if (tmp->content < next->content
		&& next->content > next->next->content)
	{
		swap(stack_b, 'b');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
	}
}

void	three_or_two(t_list **stack_a, t_list **stack_b, int nb)
{
	if (nb == 2)
	{
		trot(stack_a, 2);
		push(stack_b, stack_a, 'a');
		push(stack_b, stack_a, 'a');
		trot(stack_a, 2);
	}
	else
	{
//		trot(stack_a, 3);
		sort_three_from_b(stack_a, stack_b);
//		push(stack_b, stack_a, 'a');
//		push(stack_b, stack_a, 'a');
//		push(stack_b, stack_a, 'a');
//		trot(stack_a, 3);	
	}
}

int	from_b_to_a(t_list **stack_a, t_list **stack_b, int nb, int mediane)
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
	while (nb > pa)
	{
		rev_rotate(stack_b, 'b');
		nb--;
	}
	return (pa);
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

void	truc(t_list **stack_a, t_list **stack_b, int nb)
{
	t_list	*tmp;
	int		*tab;
	int		i;
	int		mediane;
	int		pb;

	if (nb <= 3)
		trot(stack_a, nb);
	else
	{
		tab = NULL;
		tab = create_tab(tab, stack_a, nb);
		mediane = get_mediane(tab, stack_a, nb);
		i = 0;
		pb = 0;
		while (i < nb)
		{
			tmp = *stack_a;
			if (tmp->index <= mediane)
			{
				push(stack_a, stack_b, 'b');
				pb++;
			}
			else
				rotate(stack_a, 'a');
			i++;
		}
		i = 0;
		while (i < nb - pb)
		{
			rev_rotate(stack_a, 'a');
			i++;
		}
		truc(stack_a, stack_b, nb - pb);
		tri(stack_a, stack_b, pb);
		free(tab);
	}
}

void	trot(t_list **stack_a, int nb)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (nb == 2)
	{
		if (tmp->content > tmp->next->content)
			swap(stack_a, 'a');
	}
	else
		troi(stack_a);
}

void	troi(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack_a;
	next = tmp->next;
	if (tmp->content > next->content && next->content > next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content > next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else
		troi_2(stack_a, tmp, next);
}

void	troi_2(t_list **stack_a, t_list *tmp, t_list *next)
{
	if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content < next->next->content)
	{
		swap(stack_a, 'a');
	}
	else if (tmp->content < next->content && next->content > next->next->content
		&& tmp->content < next->next->content)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (tmp->content < next->content
		&& next->content > next->next->content)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
		swap(stack_a, 'a');
	}
}
