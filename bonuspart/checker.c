/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:30:16 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 22:32:23 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/push_swap.h"

int	ft_strcmp(char *line, char *line2)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != line2[i])
			return (0);
		i++;
	}
	return (1);
}

void	do_op_two(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "rr\n"))
	{
		rotate(stack_a, 'z');
		rotate(stack_b, 'z');
	}
	else if (ft_strcmp(line, "rra\n"))
		rev_rotate(stack_a, 'z');
	else if (ft_strcmp(line, "rrb\n"))
		rev_rotate(stack_b, 'z');
	else if (ft_strcmp(line, "rrr\n"))
	{
		rev_rotate(stack_a, 'z');
		rev_rotate(stack_b, 'z');
	}
	else
		write (1, "Error\n", 6);
}

void	do_op(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(line, "sa\n"))
		swap(stack_a, 'z');
	else if (ft_strcmp(line, "sb\n"))
		swap(stack_b, 'z');
	else if (ft_strcmp(line, "pa\n"))
		push(stack_b, stack_a, 'z');
	else if (ft_strcmp(line, "pb\n"))
		push(stack_a, stack_b, 'z');
	else if (ft_strcmp(line, "ss\n"))
	{
		swap(stack_a, 'z');
		swap(stack_b, 'z');
	}
	else if (ft_strcmp(line, "ra\n"))
		rotate(stack_a, 'z');
	else if (ft_strcmp(line, "rb\n"))
		rotate(stack_b, 'z');
	else
		do_op_two(line, stack_a, stack_b);
}

void	checker_core(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_op(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (ft_checksort(stack_a))
		write(1, "OK\n", 3);
	else if (!ft_checksort(stack_a))
		write(1, "KO\n", 3);
}
