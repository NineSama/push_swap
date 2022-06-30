/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:33:35 by mfroissa          #+#    #+#             */
/*   Updated: 2022/06/30 21:57:20 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP__H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_lists
{
	struct s_list	*listA;
	struct s_list	*listB;
}					t_lists;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}								t_list;

t_list	*init_list(int content);
int		ft_atoi(char *str);
#endif
