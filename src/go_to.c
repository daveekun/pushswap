/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:39:05 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/02 17:54:17 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void go_to_top_b(t_stack *b)
{
	int i;

	i = 0;
	while (i < b->size && b->size > 0 && b->s[i] != get_max(b))
		i++;
	if (i > b->size - i)
	{
		i = b->size - i;
		while (i-- > 0)
			r_rotate_list(b);
	}
	else
	{
		while (i-- > 0)
		rotate_list(b);
	}
}

void rotate_correct_a(t_stack *a, t_stack *b, int min_index, int b_rot)
{
	if (b_rot > 0)
	{
		min_index = a->size - min_index;
		while (min_index-- > 0)
			r_rotate_list(a);
		while (b_rot-- > 0)
			rotate_list(b);
	}
	else
	{
		b_rot *= -1;
		min_index = a->size - min_index;
		while (b_rot > 0 && min_index > 0)
		{
			b_rot--;
			min_index--;
			r_rotate_both(a, b);
		}
		while (b_rot-- > 0)
			r_rotate_list(b);
		while (min_index-- > 0)
			r_rotate_list(a);
	}
}

void rev_rotate_correct_a(t_stack *a, t_stack *b, int min_index, int b_rot)
{
	if (b_rot > 0)
	{
		while (min_index > 0 && b_rot > 0)
		{
			b_rot--;
			min_index--;	
			rotate_both(a, b);
		}
		while (b_rot-- > 0)
			rotate_list(b);
		while (min_index-- > 0)
			rotate_list(a);
	}
	else
	{
		b_rot *= -1;
		while (b_rot-- > 0)
			r_rotate_list(b);
		while (min_index-- > 0)
			rotate_list(a);
	}
}
