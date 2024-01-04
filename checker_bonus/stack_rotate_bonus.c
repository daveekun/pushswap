/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:20:49 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 21:58:45 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_stack *s)
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
}

void	r_rotate_both(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size == 0 || a->size == 1)
		return ;
	temp = a->s[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->s[i] = a->s[i - 1];
		i--;
	}
	a->s[0] = temp;
	if (b->size == 0 || b->size == 1)
		return ;
	temp = b->s[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->s[i] = b->s[i - 1];
		i--;
	}
	b->s[0] = temp;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size == 0 || a->size == 1)
		return ;
	temp = a->s[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->s[i] = a->s[i + 1];
		i++;
	}
	a->s[a->size - 1] = temp;
	if (b->size == 0 || b->size == 1)
		return ;
	temp = b->s[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->s[i] = b->s[i + 1];
		i++;
	}
	b->s[b->size - 1] = temp;
}

void	r_rotate_list(t_stack *s)
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
}
