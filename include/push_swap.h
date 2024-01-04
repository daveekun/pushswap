/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:28 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 22:25:36 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_stack{
	int		size;
	char	name;
	int		*s;
}	t_stack;

/* sort */
void	sort(t_stack *stack);
void	rev_rotate_correct_a(t_stack *a, t_stack *b, int min_index, int b_rot);
void	rotate_correct_a(t_stack *a, t_stack *b, int min_index, int b_rot);
void	go_to_top_b(t_stack *b);
int		get_b_rot(int val, t_stack *b);
int		get_min_rotation(t_stack *a, t_stack *b);
int		is_sorted(t_stack a);
int		print_error(void);
t_stack	try_parse(int argc, char **argv);

/* stack */
void	rotate_list(t_stack *s);
void	rotate_both(t_stack *a, t_stack *b);
void	r_rotate_list(t_stack *s);
void	r_rotate_both(t_stack *a, t_stack *b);
void	push(t_stack *a, t_stack *b);
void	switch_top(t_stack *s);
void	switch_top_both(t_stack *s1, t_stack *s2);

/* utils */
int		abs(int a);
int		min(int a, int b);
int		max(int a, int b);
int		get_max(t_stack *b);
int		get_min(t_stack *b);
int		is_number(char *s);
int		is_in_stack(int num, t_stack s, int current);

#endif