/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:52:52 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 17:43:03 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if ('0' <= s[i] && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_in_stack(int num, t_stack s, int current)
{
	int	i;

	i = 0;
	while (i < current -1)
	{
		if (num == s.s[i] && i != current)
			return (1);
		i++;
	}
	return (0);
}
