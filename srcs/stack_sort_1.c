/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/08 21:21:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_list *stack, int middle);
static int	rev_check_stack(t_list *stack, int middle);
void	rev_split_stack(t_list **stack_a, t_list **stack_b, int *array, int len);
void	printf_reverse(int *array, int len);

void split_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	push_count;
	int	*array_b;

	middle = array[len / 2];
	push_count = 0;
	while (check_stack(*stack_a, middle))
	{
		if (*((int *)(*stack_a)->content) < middle)
		{
			push(stack_b, stack_a, "pb");
			push_count++;
		}
		else
			rotate(stack_a, "ra");
	}
	free(array);
	array = sort_array(*stack_a, ft_lstsize(*stack_a));
	array_b = sort_array(*stack_b, push_count);
	if (ft_lstsize(*stack_a) > 2)
	{
		split_stack(stack_a, stack_b, array, ft_lstsize(*stack_a));
		//rev_split_stack(stack_a, stack_b, array_b, push_count);
	}
	else
	{
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
	}
	printf_reverse(array_b, push_count);
}

void	rev_split_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	rb_count;

	middle = array[len / 2];
	rb_count = 0;
	if (len == 1)
	{
		push(stack_a, stack_b, "pa");
		return ;
	}
	while (rev_check_stack(*stack_b, middle))
	{
		if (*((int *)(*stack_b)->content) > middle)
			push(stack_a, stack_b, "pa");
		else
		{
			rotate(stack_b, "rb");
			rb_count++;
		}
	}
	while (rb_count > 0)
	{
		reverse_rotate(stack_b, "rrb");
		rb_count--;
	}
	
}

static int	check_stack(t_list *stack, int middle)
{
	while (stack != NULL)
	{
		if (*((int *)stack->content) < middle)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	rev_check_stack(t_list *stack, int middle)
{
		while (stack != NULL)
	{
		if (*((int *)stack->content) > middle)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	printf_reverse(int *array, int len)
{
	int index = 0;

	ft_printf("Array_rev: ");
	while (index < len)
	{
		ft_printf("% d", array[index]);
		index++;
	}
	ft_putchar_fd('\n', 1);
}