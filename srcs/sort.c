/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:42:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 00:49:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(t_list *stack, int len);
static void	swap_array(int *a, int *b);

/* Sorts an array using bubble sort algorithm.*/
int	*sort_array(t_list *stack, int length)
{
	int	*array;
	int	index;
	int	flag;

	if (!stack)
		return (NULL);
	array = get_array(stack, length);
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

/* Fills the array with size number values of the stack.*/
static int	*get_array(t_list *stack, int size)
{
	int	*array;
	int	array_index;

	array = malloc(sizeof(*array) * (size));
	if (!array)
		return (NULL);
	array_index = 0;
	while (size > 0)
	{
		array[array_index] = *((int *)stack->content);
		array_index++;
		stack = stack->next;
		size--;
	}
	return (array);
}

/* Swaps two values*/
static void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
