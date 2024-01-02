/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:19:26 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/02 17:41:56 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_back(t_stack *a, t_stack *b)
{
	int	needed_reverse;

	needed_reverse = 3;
	while (b->size)
	{
		while (b->s[0] <= a->s[a->size - 1] && needed_reverse > 0)
		{
			needed_reverse--;
			r_rotate_list(a);
		}
		push(b, a);
	}
	while (a->size > 3 && needed_reverse-- > 0)
		r_rotate_list(a);
}

static void sort_three(t_stack *s)
{
	if (s->size == 1 || s->size == 0)
		return ;
	else if (s->size == 2)
	{
		if (s->s[0] > s->s[1])
			switch_top(s);
	}
	else if (s->s[0] <= s->s[1] && s->s[1] <= s->s[2] && s->s[0] <= s->s[2])
		return ;
	else if (s->s[0] <= s->s[1] && s->s[1] >= s->s[2] && s->s[0] <= s->s[2])
	{
		switch_top(s);
		rotate_list(s);
	}
	else if (s->s[0] >= s->s[1] && s->s[1] <= s->s[2] && s->s[0] <= s->s[2])
		switch_top(s);
	else if (s->s[0] <= s->s[1] && s->s[1] >= s->s[2] && s->s[0] >= s->s[2])
		r_rotate_list(s);
	else if (s->s[0] >= s->s[1] && s->s[1] >= s->s[2] && s->s[0] >= s->s[2])
	{
		switch_top(s);
		r_rotate_list(s);
	}
	else if (s->s[0] >= s->s[1] && s->s[1] <= s->s[2] && s->s[0] >= s->s[2])
		rotate_list(s);
}

static void	semi_sort(t_stack *a, t_stack *b)
{
	int min_index;
	int b_rot;
	int i;
	
	while (a->size > 3)
	{
		min_index = get_min_rotation(a, b);
		b_rot = get_b_rot(a->s[min_index], b);
		if (min_index > a->size - min_index)
			rotate_correct_a(a, b, min_index, b_rot);	
		else
			rev_rotate_correct_a(a, b, min_index, b_rot);	
		push(a, b);
	}
	go_to_top_b(b);	
}

void	sort(t_stack *stack)
{
	t_stack new_stack;

	new_stack=(t_stack){.s=0, .size=0, .name='b'};
	semi_sort(stack, &new_stack);
	sort_three(stack);
	put_back(stack, &new_stack);
}
