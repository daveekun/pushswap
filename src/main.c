/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:00 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 22:25:09 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc < 2)
		return (0);
	a = try_parse(argc, argv);
	if (a.size == 0 || a.size == -1)
	{
		free(a.s);
		return (print_error());
	}
	a.name = 'a';
	if (!is_sorted(a))
		sort(&a);
}
