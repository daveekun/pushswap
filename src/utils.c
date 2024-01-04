/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:00:45 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 14:25:36 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	get_max(t_stack *b)
{
	int	max;
	int	i;

	i = 0;
	max = -2147483648;
	while (i < b->size)
	{
		if (b->s[i] > max)
			max = b->s[i];
		i++;
	}
	return (max);
}

int	get_min(t_stack *b)
{
	int	min;
	int	i;

	i = 0;
	min = 2147483647;
	while (i < b->size)
	{
		if (b->s[i] < min)
			min = b->s[i];
		i++;
	}
	return (min);
}
