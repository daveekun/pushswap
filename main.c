/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:00 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/10 18:06:57 by dhorvath         ###   ########.fr       */
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
	int	steps;
	int min_steps;
	int min_index;
	int i;
	int	initial_rot;
	int b_rotation_need;
	
	while (a->size > 2)
	{
		min_steps = 10000;
		initial_rot = 0;
		while (initial_rot < a->size)
		{
			if ()
			initial_rot++;
		}		
	}	
}

int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
