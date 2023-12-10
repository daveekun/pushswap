/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:00 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/10 18:37:26 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack);

int	main(void)
{
	int f[5] = {3,2,1,4,5};
	t_stack a;

	a = (t_stack){.s=&f[0], .size=5};
	sort(&a);
	print_list(&a);
}

void	sort(t_stack *stack)
{
	// "sort" the first blocksize elements, repeat until empty or 1-2 elements
	//		find median, above top, under bottom
	// find biggest, second or third element in b, put it into its place, check what is quickest
	// repeat until b is empty
	t_stack new_stack;

	semi_sort(stack, &new_stack);
	put_back(stack, &new_stack);
}

void	put_back(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		push(b, a);
	}
}

void	semi_sort(t_stack *a, t_stack *b)
{
	int min_steps;
	int min_index;
	int	initial_rot;
	
	while (a->size > 0)
	{
		/* find minimum step movement */
		min_steps = 100000;
		initial_rot = 0;
		while (initial_rot < a->size)
		{
			if (abs(get_b_rot(a->s[initial_rot], b)) + min(initial_rot, a->size - initial_rot) < min_steps)
			{
				min_index = initial_rot;
				min_steps = abs(get_b_rot(a->s[initial_rot], b)) + min(initial_rot, a->size - initial_rot);
			}
			initial_rot++;
		}
		/* do min step move NEEDS OPTIMSING EASY STEPS */
		int b_rot = get_b_rot(a->s[min_index], b);
		while (min_index-- > 0)
			rotate_list(a);
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

int	get_b_rot(int val, t_stack *b)
{
	int rot;

	if (val < b->s[0] && val < b->s[b->size - 1])
		return (0);
	rot = 1;
	while (rot < b->size - 1)
	{
		if (val < b->s[rot - 1] && val > b->s[rot + 1])
		{
			if (rot < b->size - rot)
				return (rot);
			return (-1 * (b->size - rot));
		}
		rot++;
	}
	return (-1);
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
