/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:05:09 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/07 16:44:53 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"

void rotate_list(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size == 0 || s->size == 1)
		return ;
	temp = s->s[0];
	i = 0;
	while (i < s->size - 1)
	{
		s[i] = s[i + 1];
		i++;
	}	
	s->s[s->size - 1] = temp;
}

void r_rotate_list(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size == 0 || s->size == 1)
		return ;
	temp = s->s[s->size - 1];
	i = 0;
	while (i < s->size - 1)
	{
		s[i + 1] = s[i];
		i++;
	}	
	s->s[0] = temp;
}

void print_list(t_stack *s)
{
	int	i;

	while (i < s->size)
		printf("%i\n", s->s[i++]);
}

void push_to_stack(t_stack *stack, int val)
{
	int *old;
	int	i;

	old = stack->s;
	stack->s = malloc((stack->size + 1) * sizeof(int));	
	i = 0;
	while (i < stack->size)
	{
		stack->s[i] = old[i];
		i++;	
	}
	stack->s[i] = val;
	stack->size += 1;
	free(old);
}

void remove_from_stack(t_stack *stack)
{
	int *old;
	int	i;

	old = stack->s;
	stack->s = malloc((stack->size - 1) * sizeof(int));	
	i = 1;
	while (i < stack->size)
	{
		stack->s[i] = old[i];
		i++;	
	}
	stack->size -= 1;
	free(old);
}

void push(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_to_stack(b, a->s[0]);
	remove_from_stack(a);	
}

void switch_top(t_stack *s)
{
	int	temp;

	if (s->size == 0 || s->size == 1)
		return ;
	temp = s->s[0];
	s->s[0] = s->s[1];
	s->s[1] = temp;
}