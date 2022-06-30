/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:38:07 by mfroissa          #+#    #+#             */
/*   Updated: 2022/06/18 01:49:36 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_min(t_list *list)
{
	int		tmp;
	t_list	*result;

	tmp = list->content;
	result = list;
	while (list)
	{
		if (list->content < tmp)
		{
			tmp = list->content;
			result = list;
		}
		list = list->next;
	}
	return (result);
}

t_list	*get_max(t_list *list)
{
	int		tmp;
	t_list	*result;

	tmp = list->content;
	result = list;
	while (list)
	{
		if (list->content > tmp)
		{
			tmp = list->content;
			result = list;
		}
		list = list->next;
	}
	return (result);
}

