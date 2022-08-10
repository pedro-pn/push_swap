/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:42:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/10 14:30:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(t_list *stack_a, int stack_len);
static void	swap_array(int *a, int *b);

int	*sort_array(t_list *stack_a, int length)
{
	int	*array;
	int	index;
	int	flag;

	if (!stack_a)
		return (NULL);
	array = get_array(stack_a, length);
	if (!array)
		return (NULL);
	index = 0;
	flag = 0;
	while (flag != length - 1)
	{
		if (index == length - 1)
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

static int	*get_array(t_list *stack_a, int stack_len)
{
	int	*array;
	int	array_index;

	array = malloc(sizeof(*array) * (stack_len));
	if (!array)
		return (NULL);
	array_index = 0;
	while (stack_len > 0)
	{
		array[array_index] = *((int *)stack_a->content);
		array_index++;
		stack_a = stack_a->next;
		stack_len--;
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
