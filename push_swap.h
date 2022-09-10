/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:33:35 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/10 19:05:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}								t_list;

/* operations.c */
void	swap(t_list **stack, char c);
void	push(t_list **stack_1, t_list **stack_2, char c);
void	rotate(t_list **stack, char c);
t_list	*del_last(t_list **stack, int n, char c);
void	rev_rotate(t_list **stack, char c);

/* operation_duo.c */
void	swap_duo(t_list **stack_a, t_list **stack_b);
void	rotate_duo(t_list **stack_a, t_list **stack_b);
void	rev_rotate_duo(t_list **stack_a, t_list **stack_b);

/* valid.c */
int		ft_checksort(t_list **stack);
int		ft_checkdup(int ac, char **av);
int		ft_checknum(int ac, char **av);
int		ft_checkint(int ac, char **av);
int		valid(int ac, char **av);

/* prog.c */
long	ft_atoi(char *str);
void	ft_print(t_list **stack);

/* lst.c */
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, int content);
void	ft_lstadd_front(t_list **lst, int content);
t_list	*ft_lstlast(t_list *stack);
int		ft_lstsize(t_list **stack);

/* tabsort.c */
int		*create_tab(int *tab, t_list **stack, int nb);
void	ft_sort_tab(int	*tab, int size);
void	put_index(int *tab, t_list **stack, int ac);
int		get_mediane_tiers(int *tab, t_list **stack, int nb);
int		get_mediane(int	*tab, t_list **stack, int nb);

/* algo_utils.c */
int		from_b_to_a_last(t_list **stack_a, t_list **stack_b, int nb, int mediane);
void	tri_last_chunk(t_list **stack_a, t_list **stack_b, int nb);

/* algo.c */
int		push_chunks(t_list **stack_a, t_list **stack_b, int size, int mediane);
int		push_chunks_no_op(t_list **stack_a, int size, int mediane);
int		push_chunks_no_zero(t_list **stack_a, t_list **stack_b, int size, int mediane);
void	algo(t_list **stack_a, t_list **stack_b, int size);
void	send_back(t_list **stack_a, t_list **stack_b, t_list **number);
void	sort_three_from_b(t_list **stack_a, t_list **stack_b);
void	sort_three_from_b_two(t_list **stack_a, t_list **stack_b, t_list *tmp, t_list *next);
void	three_or_two(t_list **stack_a, t_list **stack_b, int nb);
int		from_b_to_a(t_list **stack_a, t_list **stack_b, int nb, int mediane);
void	tri(t_list **stack_a, t_list **stack_b, int nb);
void	truc(t_list **stack_a, t_list **stack_b, int nb);
void	five(t_list **stack_a, t_list **stack_b);
void	trot(t_list **stack_a, int nb);
void	troi(t_list **stack_a);
void	troi_2(t_list **stack_a, t_list *tmp, t_list *next);
void	only_three(t_list **stack_a);

#endif
