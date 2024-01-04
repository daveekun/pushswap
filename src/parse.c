/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:43 by dhorvath          #+#    #+#             */
/*   Updated: 2024/01/04 20:12:47 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_stack	parse_separate(int count, char **args, int is_one)
{
	int		i;
	t_stack	res;

	res.s = NULL;
	res.size = count;
	if (count == -1 || count == 0)
		return (res);
	res.s = malloc(count * sizeof(int));
	i = -1;
	while (args && args[++i])
	{
		res.s[i] = ft_atoi(args[i]);
		if ((res.s[i] < 0 && ft_strchr(args[i], '-') == NULL)
			|| (res.s[i] > 0 && ft_strchr(args[i], '-') != NULL)
			|| is_in_stack(res.s[i], res, i)
			|| !is_number(args[i]))
		{
			res.size = -1;
			return (res);
		}
	}
	if (is_one)
		free(args);
	return (res);
}

static t_stack	parse_as_one(char *s)
{
	const char	**args = (const char **)ft_split(s, ' ');
	int			i;

	i = -1;
	while (args && args[++i])
		;
	if (!args)
		i = -1;
	return (parse_separate(i, (char **)args, 69420));
}

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		if (a.s[i] > a.s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

t_stack	try_parse(int argc, char **argv)
{
	if (argc == 2)
		return (parse_as_one(argv[1]));
	else
		return (parse_separate(argc - 1, &argv[1], 0));
}
