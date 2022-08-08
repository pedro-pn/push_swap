/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:42:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/08 13:16:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(int argc, char *argv[]);
static void	swap_array(int *a, int *b);

int	*sort_array(int argc, char *argv[])
{
	int	*array;
	int	index;
	int	flag;

	array = get_array(argc, argv);
	if (!array)
		return (NULL);
	index = 0;
	flag = 0;
	while (flag != argc - 2)
	{
		if (index == argc - 2)
		{
			index = 0;
			flag = 0;
		}
		if (array[index] < array[index + 1])
			flag++;
		else if (array[index] > array[index + 1])
			swap_array(&array[index], &array[index + 1]);
		index++;
	}
	return (array);
}

static int	*get_array(int argc, char *argv[])
{
	int	*array;
	int	index;
	int	array_index;

	array = malloc(sizeof(*array) * (argc - 1));
	if (!array)
		return (NULL);
	index = 1;
	array_index = 0;
	while (index < argc)
	{
		array[array_index] = ft_atoi(argv[index]);
		index++;
		array_index++;
	}
	return (array);
}

static void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
