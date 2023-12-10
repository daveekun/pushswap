/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:05:09 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/10 19:08:18 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
		s->s[i] = s->s[i + 1];
		i++;
	}	
	s->s[s->size - 1] = temp;
	printf("rotate %c\n", s->name);
}

void r_rotate_list(t_stack *s)
{
	int	temp;
	int	i;

	if (s->size == 0 || s->size == 1)
		return ;
	temp = s->s[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->s[i] = s->s[i - 1];
		i--;
	}	
	s->s[0] = temp;
	printf("reverse rotate %c\n", s->name);
}

void print_list(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
		printf("%i ", s->s[i++]);
	printf("\n");
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
		stack->s[i + 1] = old[i];
		i++;
	}
	stack->s[0] = val;
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
		stack->s[i - 1] = old[i];
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
	printf("push from %c to %c\n", a->name, b->name);
	print_list(a);
	print_list(b);
}

void switch_top(t_stack *s)
{
	int	temp;

	if (s->size == 0 || s->size == 1)
		return ;
	temp = s->s[0];
	s->s[0] = s->s[1];
	s->s[1] = temp;
	printf("switch top %c\n", s->name);
}