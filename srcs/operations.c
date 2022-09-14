/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:47:04 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/14 14:13:03 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack, char c)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = (*stack)->content;
	j = (*stack)->index;
	tmp = (*stack)->next;
	(*stack)->content = tmp->content;
	(*stack)->index = tmp->index;
	tmp->content = i;
	tmp->index = j;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	push(t_list **stack_1, t_list **stack_2, char c)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp = *stack_1;
	tmp1 = *stack_1;
	tmp1 = tmp1->next;
	(*stack_1) = tmp1;
	if (!(*stack_2))
	{
		*stack_2 = tmp;
		(*stack_2)->next = NULL;
	}
	else
	{
		tmp2 = *stack_2;
		*stack_2 = tmp;
		(*stack_2)->next = tmp2;
	}
	if (c == 'a')
		write (1, "pa\n", 3);
	else if (c == 'b')
		write (1, "pb\n", 3);
}

void	rotate(t_list **stack, char c)
{
	t_list	*tmp;
	t_list	*tmp_last;

	if (!(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp_last = ft_lstlast(tmp);
	tmp_last->next = tmp;
	tmp_last = tmp_last->next;
	tmp_last->next = NULL;
	if (c == 'a')
		write (1, "ra\n", 3);
	else if (c == 'b')
		write (1, "rb\n", 3);
}

t_list	*del_last(t_list **stack, int n, char c)
{
	t_list	*tmp;

	tmp = *stack;
	if (c == 'c')
	{
		while ((tmp->next)->content != n && tmp->next)
			tmp = tmp->next;
		if ((tmp->next)->content == n)
			return (tmp);
	}
	else if (c == 'i')
	{
		while ((tmp->next)->index != n && tmp->next)
			tmp = tmp->next;
		if ((tmp->next)->index == n)
			return (tmp);
	}
	return (NULL);
}

void	rev_rotate(t_list **stack, char c)
{
	t_list	*tmp;
	t_list	*tmp_last;

	tmp = *stack;
	tmp_last = ft_lstlast(tmp);
	if (!(*stack)->next)
		return ;
	*stack = del_last(stack, tmp_last->content, 'c');
	*stack = del_last(stack, tmp_last->index, 'i');
	(*stack)->next = NULL;
	*stack = tmp_last;
	(*stack)->next = tmp;
	if (c == 'a')
		write (1, "rra\n", 4);
	else if (c == 'b')
		write (1, "rrb\n", 4);
}
