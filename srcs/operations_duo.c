/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_duo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:12:38 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/09 21:59:18 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_duo(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	write (1, "ss\n", 3);
}

void	rotate_duo(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	write (1, "rr\n", 3);
}

void	rev_rotate_duo(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a, 'r');
	rev_rotate(stack_b, 'r');
	write (1, "rrr\n", 4);
}
