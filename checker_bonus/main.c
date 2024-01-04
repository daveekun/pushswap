/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:44:37 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 22:25:14 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	check_if_sorted(t_stack *a);

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
		check_if_sorted(&a);
}

void	do_error(t_stack *a, t_stack b)
{
	free(a->s);
	free(b.s);
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	check_cmd(char *cmd, t_stack *a, t_stack b)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate_list(a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate_list(&b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rotate_both(a, &b);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		switch_top(a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		switch_top(&b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		switch_top_both(a, &b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		r_rotate_list(a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		r_rotate_list(&b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		r_rotate_both(a, &b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push(&b, a);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push(a, &b);
	else
		do_error(a, b);
}

void	check_if_sorted(t_stack *a)
{
	t_stack	b;
	char	*cmd;

	b = (t_stack){0, 'b', 0};
	cmd = get_next_line(0);
	while (cmd)
	{
		check_cmd(cmd, a, b);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(*a) && b.size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(b.s);
	free(a->s);
}
