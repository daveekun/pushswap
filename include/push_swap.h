/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:28 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/02 18:02:34 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack{
	int size;
	char name;
	int	*s;
} t_stack;

void	sort(t_stack *stack);
int		get_b_rot(int val, t_stack *b);
int		get_min_rotation(t_stack *a, t_stack *b);
int		is_sorted(t_stack a);
int		print_usage(void);
t_stack try_parse(int argc, char **argv);

/* stack */
void	rotate_list(t_stack *s);
void	r_rotate_both(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	r_rotate_list(t_stack *s);
void	push(t_stack *a, t_stack *b);
void	switch_top(t_stack *s);
/* utils */
int 	abs(int a);
int 	min(int a, int b);
int 	max(int a, int b);
int 	get_max(t_stack *b);
int 	get_min(t_stack *b);

#endif