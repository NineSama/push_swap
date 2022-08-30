/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:33:35 by mfroissa          #+#    #+#             */
/*   Updated: 2022/08/30 20:37:03 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP__H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_big_list
{
	struct s_list	*listA;
	struct s_list	*listB;
}					t_big_list;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}								t_list;

/* operations.c */
void	swap(t_list **stacka, char c);
void	push(t_list **stack_1, t_list **stackB, char c);

/* prog.c */
int	ft_checkdup(int ac, char **av);
int ft_atoi(char *str);

/* lst.c */
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, int content);
t_list	*ft_lstlast(t_list **lst);
#endif
