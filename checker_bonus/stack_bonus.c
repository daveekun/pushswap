/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:05:09 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 21:58:22 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_stack *stack, int val)
{
	int	*old;
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

void	remove_from_stack(t_stack *stack)
{
	int	*old;
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

void	push(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_to_stack(b, a->s[0]);
	remove_from_stack(a);
}

void	switch_top(t_stack *s)
{
	int	temp;

	if (s->size == 0 || s->size == 1)
		return ;
	temp = s->s[0];
	s->s[0] = s->s[1];
	s->s[1] = temp;
}

void	switch_top_both(t_stack *s1, t_stack *s2)
{
	int	temp;

	if (s1->size == 0 || s1->size == 1)
		;
	else
	{
		temp = s1->s[0];
		s1->s[0] = s1->s[1];
		s1->s[1] = temp;
	}
	if (s2->size == 0 || s2->size == 1)
		;
	else
	{
		temp = s2->s[0];
		s2->s[0] = s2->s[1];
		s2->s[1] = temp;
	}
}
