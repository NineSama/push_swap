/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:04:08 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/14 17:40:03 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_free_list(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	free(stack);
}
