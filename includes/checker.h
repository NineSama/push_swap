/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:32:36 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/15 22:35:42 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "./push_swap.h"

int		search_n(char *line, char c);
char	*get_rest(char *buff, int n);
char	*strjoin(char *line, char *buff, int n);
char	*gnl_core(char *line, char *buff, int n);
char	*get_next_line(int fd);

void	checker_core(t_list **stack_a, t_list **stack_b);
void	do_op(char *line, t_list **stack_a, t_list **stack_b);
void	do_op_two(char *line, t_list **stack_a, t_list **stack_b);
int		ft_strcmp(char *line, char *line2);

#endif