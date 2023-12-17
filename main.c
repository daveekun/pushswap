/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:00 by dhorvath          #+#    #+#             */
/*   Updated: 2023/12/17 21:26:25 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define SMALLEST 2147483647

void	sort(t_stack *stack);
void	put_back(t_stack *a, t_stack *b);
void	semi_sort(t_stack *a, t_stack *b);
int abs(int a);
int	get_b_rot(int val, t_stack *b);
int min(int a, int b);
void sort_three(t_stack *s);
t_stack try_parse(int argc, char **argv);

int print_usage(void)
{
	printf("Usage:\t./pushswap int1 int2 int3 ... intn \n\t\t\tOR\n\t./pushswap \"int1 int2 int3 ... intn\"\n");
	return (0);
}

int is_sorted(t_stack a)
{
	int i;
	
	i = 0;
	while (i < a.size - 1)
	{
		if (a.s[i] > a.s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
	print_list(&a);
	if (!is_sorted(a))
		sort(&a);
	print_list(&a);
}

t_stack parse_separate(int count, char **args)
{
	int i;
	t_stack res;

	res.s = NULL;
	res.size = count;
	if (count == -1 || count == 0)
		return (res);
	res.s = malloc(count * sizeof(int));
	i = -1;
	while (args && args[++i])
	{
		res.s[i] = ft_atoi(args[i]);
		if (res.s[i] < 0 && ft_strchr(args[i], '-') == NULL)
		{
			res.size = -1;
			return (res);
		}
	}
	return (res);
}

t_stack parse_as_one(char *s)
{
	const char **args = (const char **)ft_split(s, ' ');
	int i;

	i = -1;
	while (args && args[++i])
		;
	return (parse_separate(i, (char **)args));
}

t_stack try_parse(int argc, char **argv)
{
	if (argc == 2)
		return (parse_as_one(argv[1]));
	else 
		return (parse_separate(argc - 1, &argv[1]));
}

void	sort(t_stack *stack)
{
	// "sort" the first blocksize elements, repeat until empty or 1-2 elements
	//		find median, above top, under bottom
	// find biggest, second or third element in b, put it into its place, check what is quickest
	// repeat until b is empty
	t_stack new_stack;

	new_stack=(t_stack){.s=0, .size=0, .name='b'};
	semi_sort(stack, &new_stack);
	print_list(&new_stack);
	sort_three(stack);
	put_back(stack, &new_stack);
}

void	put_back(t_stack *a, t_stack *b)
{
	int	needed_reverse;

	needed_reverse = 3;
	while (b->size)
	{
		while (b->s[0] <= a->s[a->size - 1] && needed_reverse > 0)
		{
			needed_reverse--;
			r_rotate_list(a);
		}
		push(b, a);
	}
	while (a->size > 3 && needed_reverse-- > 0)
		r_rotate_list(a);
}

void	semi_sort(t_stack *a, t_stack *b)
{
	int min_steps;
	int min_index;
	int	initial_rot;
	
	while (a->size > 3)
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
		if (b_rot > 0 && b_rot != SMALLEST)
		{
			while (b_rot-- > 0)
				rotate_list(b);
		}
		else
		{
			b_rot *= -1;
			while (b_rot != SMALLEST && b_rot-- > 0)
				r_rotate_list(b);
		}
		push(a, b);
		print_list(b);
		if (b_rot == SMALLEST)
			r_rotate_list(b);
	}
	while (b->size > 0 && b->s[b->size - 1] >= b->s[0])
		rotate_list(b);
}

int get_max(t_stack *b)
{
	int max = -2147483648;
	int i = 0;
	while(i < b->size)
	{
		if (b->s[i] > max)
			max = b->s[i];
		i++;
	}
	return (max);
}

int get_min(t_stack *b)
{
	int min = 2147483647;
	int i = 0;
	while(i < b->size)
	{
		if (b->s[i] < min)
			min = b->s[i];
		i++;
	}
	return (min);
}

int	handle_outside(int val, t_stack *b)
{
	int i;
	int max;

	i = 0;
	max = get_max(b);
	while (i < b->size && b->s[i] != max)
		i++;
	while (b->s[i] == max)
		i++;
	if (i == 0)
		return (0);
	i--;
	return (i);
}

int	get_b_rot(int val, t_stack *b)
{
	int rot;

	if (b->size != 0 && b->size != 1 && (val > get_max(b) || val < get_min(b)))
		return (handle_outside(val, b));
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
					return (rot + 1);
			}
			rot++;
		}
	}
	return (100);
}

int abs(int a)
{
	if (a == SMALLEST)
		return (1);
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

void sort_three(t_stack *s)
{
	if (s->size == 1 || s->size == 0)
		return ;
	else if (s->size == 2)
	{
		if (s->s[0] > s->s[1])
			switch_top(s);
	}
	else if (s->s[0] <= s->s[1] && s->s[1] <= s->s[2] && s->s[0] <= s->s[2])
		return ;
	else if (s->s[0] <= s->s[1] && s->s[1] >= s->s[2] && s->s[0] <= s->s[2])
	{
		switch_top(s);
		rotate_list(s);
	}
	else if (s->s[0] >= s->s[1] && s->s[1] <= s->s[2] && s->s[0] <= s->s[2])
		switch_top(s);
	else if (s->s[0] <= s->s[1] && s->s[1] >= s->s[2] && s->s[0] >= s->s[2])
		r_rotate_list(s);
	else if (s->s[0] >= s->s[1] && s->s[1] >= s->s[2] && s->s[0] >= s->s[2])
	{
		switch_top(s);
		r_rotate_list(s);
	}
	else if (s->s[0] >= s->s[1] && s->s[1] <= s->s[2] && s->s[0] >= s->s[2])
		rotate_list(s);
}
