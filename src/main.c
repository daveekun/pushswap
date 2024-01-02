/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:00 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/02 17:40:19 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_stack a;

	a = try_parse(argc, argv);
	if (a.size == 0 || a.size == -1)
	{
		free(a.s);
		return (print_usage());
	}
	a.name = 'a';
	if (!is_sorted(a))
		sort(&a);
}
