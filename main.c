/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:00 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/10 18:20:01 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	
}

void	sort(t_stack *stack, int block_size)
{
	// "sort" the first blocksize elements, repeat until empty or 1-2 elements
	//		find median, above top, under bottom
	// find biggest, second or third element in b, put it into its place, check what is quickest
	// repeat until b is empty
	t_stack new_stack;

	semi_sort(stack, &new_stack);
	put_back(stack, &new_stack);
}

void	semi_sort(t_stack *a, t_stack *b)
{
	int min_steps;
	int min_index;
	int	initial_rot;
	
	while (a->size > 2)
	{
		/* find minimum step movement */
		min_steps = 100000;
		initial_rot = 0;
		while (initial_rot < a->size)
		{
			if (get_b_rot(a->s[initial_rot], b) + min(initial_rot, a->size - initial_rot) < min_steps)
			{
				min_index = initial_rot;
				min_steps = get_b_rot(a->s[initial_rot], b) + min(initial_rot, a->size - initial_rot);
			}
			initial_rot++;
		}
		/* do min step move NEEDS OPTIMSING EASY STEPS */
		while (min_index-- > 0)
			rotate_list(a);
		int b_rot = get_b_rot(a->s[initial_rot], b);
		if (b_rot > 0)
		{
			while (b_rot-- > 0)
				rotate_list(b);
		}
		else
		{
			b_rot *= -1;
			while (b_rot-- > 0)
				r_rotate_list(b);
		}
		push(a, b);
	}	
}

int abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
