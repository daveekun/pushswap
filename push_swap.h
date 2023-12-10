/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:28 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/10 19:08:20 by dhorvath         ###   ########.fr       */
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

void rotate_list(t_stack *s);
void r_rotate_list(t_stack *s);
void print_list(t_stack *s);
void push(t_stack *a, t_stack *b);
void switch_top(t_stack *s);

#endif