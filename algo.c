/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:42:29 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/10 22:25:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_chunks(t_list **stack_a, t_list **stack_b, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;
	int		quantity;

	quantity = 0;
	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		tmp2 = (*stack_a)->next;
		if (tmp->index < mediane)
		{
			push(stack_a, stack_b, 'b');
			if (tmp2->index > mediane && tmp2->index > (mediane * 2))
			{
				rotate_duo(stack_a, stack_b);
				size--;
			}
			else
				rotate(stack_b, 'b');
		}
		else if (tmp->index >= mediane && tmp->index < (mediane * 2))
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

int	push_chunks_no_zero(t_list **stack_a, t_list **stack_b, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	int		quantity;

	quantity = 0;
	i = 0;
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

int	push_chunks_no_op(t_list **stack_a, int size, int mediane)
{
	int		i;
	t_list	*tmp;
	int		quantity;

	quantity = 0;
	i = 0;
	tmp = *stack_a;
	while (i < size)
	{
		if (tmp->index < mediane)
			quantity++;
		tmp = tmp->next;
		i++;
	}
	return (quantity);
}

void	algo(t_list **stack_a, t_list **stack_b, int ac)
{
	int		*tab;
	int		mediane;
	t_list	**number;
	int		count;

	count = 0;
	number = malloc(sizeof(t_list));
	*number = NULL;
	while (ft_lstsize(stack_a) > 3)
	{
		tab = NULL;
		tab = create_tab(tab, stack_a, ft_lstsize(stack_a));
		if (ft_lstsize(stack_a) == ac - 1)
			put_index(tab, stack_a, ft_lstsize(stack_a));
		mediane = get_mediane(tab, stack_a, ft_lstsize(stack_a));
		if (count == 0 && ac != 6)
		{
			mediane = get_mediane_tiers(tab, stack_a, ft_lstsize(stack_a));
			ft_lstadd_front(number, push_chunks_no_op(stack_a, ft_lstsize(stack_a), mediane));
			ft_lstadd_front(number, push_chunks(stack_a, stack_b, ft_lstsize(stack_a), mediane));
		}
		if (count != 0)
			ft_lstadd_front(number, push_chunks_no_zero(stack_a, stack_b, ft_lstsize(stack_a), mediane));
		count++;
		free(tab);
	}
	if (ft_lstsize(stack_a) == 2)
		three_or_two(stack_a, stack_b, 2);
	only_three(stack_a);
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
	else
	{
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
		sort_three_from_b(stack_a, stack_b);
}

int	from_b_to_a(t_list **stack_a, t_list **stack_b, int nb, int mediane)
{
	int	i;
	int pa;
	int	count;
	t_list	*tmp;
	int	rotatee;

	i = 0;
	pa = 0;
	tmp = *stack_b;
	count = 0;
	rotatee = 0;
	while (i < nb && count != nb / 2)
	{
		tmp = *stack_b;
		if (tmp->index > mediane)
		{
			push(stack_b, stack_a, 'a');
			pa++;
			count++;
		}
		else
		{
			rotate(stack_b, 'b');
			rotatee++;
		}
		i++;
	}
	i = 0;
	while (i < rotatee)
	{
		rev_rotate(stack_b, 'b');
		i++;
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
	int		count;
	int		rotatee;

	count = 0;
	rotatee = 0;
	if (nb <= 3)
		trot(stack_a, nb);
	else
	{
		tab = NULL;
		tab = create_tab(tab, stack_a, nb);
		mediane = get_mediane(tab, stack_a, nb);
		i = 0;
		pb = 0;
		while (i < nb && count != nb / 2 + 1)
		{
			tmp = *stack_a;
			if (tmp->index <= mediane)
			{
				push(stack_a, stack_b, 'b');
				pb++;
				count++;
			}
			else
			{
				rotate(stack_a, 'a');
				rotatee++;
			}
			i++;
		}
		i = 0;
		while (i < rotatee)
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
		swap(stack_a, 'a');
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

void	only_three(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *stack_a;
	next = tmp->next;

	if (tmp->content > next->content && next->content > next->next->content)
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content > next->next->content)
		rotate(stack_a, 'a');
	else if (tmp->content > next->content && next->content < next->next->content
		&& tmp->content < next->next->content)
		swap(stack_a, 'a');
	else if (tmp->content < next->content && next->content > next->next->content
		&& tmp->content < next->next->content)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (tmp->content < next->content
		&& next->content > next->next->content)
		rev_rotate(stack_a, 'a');
}
