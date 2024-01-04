/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:17:16 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 18:00:46 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_summed_steps(t_stack *a, t_stack *b, int initial_rot)
{
	int	b_rot;
	int	minimum;
	int	b_pos;

	b_rot = get_b_rot(a->s[initial_rot], b);
	if (b_rot < 0)
		b_pos = b->size + b_rot;
	else
		b_pos = b_rot;
	minimum = max(initial_rot, b_pos);
	if (minimum > initial_rot + b->size - b_pos)
		minimum = initial_rot + b->size - b_pos;
	if (minimum > a->size - initial_rot + b_pos)
		minimum = a->size - initial_rot + b_pos;
	if (minimum > max(a->size - initial_rot, b->size - b_pos))
		minimum = max(a->size - initial_rot, b->size - b_pos);
	return (minimum);
}

static int	handle_outside(t_stack *b)
{
	int	i;
	int	max;
	int	multiple_max;

	i = 0;
	multiple_max = 0;
	max = get_max(b);
	while (i < b->size && b->s[i] != max)
		i++;
	if (i == 0)
		return (0);
	if (b->size - i < i)
		return (-1 * (b->size - i));
	return (i);
}

int	get_min_rotation(t_stack *a, t_stack *b)
{
	int	min_steps;
	int	initial_rot;
	int	min_index;

	initial_rot = 0;
	min_steps = 10000000;
	while (initial_rot < a->size)
	{
		if (get_summed_steps(a, b, initial_rot) < min_steps)
		{
			min_index = initial_rot;
			min_steps = get_summed_steps(a, b, initial_rot);
		}
		initial_rot++;
	}
	return (min_index);
}

int	get_b_rot(int val, t_stack *b)
{
	int	rot;

	if (b->size != 0 && b->size != 1 && (val > get_max(b) || val < get_min(b)))
		return (handle_outside(b));
	else
	{
		if (b->size == 0 || b->size == 1)
			return (0);
		if (b->s[0] <= val && val <= b->s[b->size - 1])
			return (0);
		rot = 0;
		while (rot < b->size - 1)
		{
			if (b->s[rot] >= val && val >= b->s[rot + 1])
			{
				if (b->size - rot - 1 < rot + 1)
					return (-1 * (b->size - rot - 1));
				return (rot + 1);
			}
			rot++;
		}
	}
	return (69420);
}
