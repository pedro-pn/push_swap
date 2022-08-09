/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:34:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/09 15:10:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack(t_list *stack, int middle);
static int	rev_check_stack(t_list *stack, int middle);
void	rev_split_stack(t_list **stack_a, t_list **stack_b, int *array, int len);
void	printf_reverse(int *array, int len);
void	chunck_a(t_list **stack_a, t_list **stack_b, int *array, int len);

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
	//printf_reverse(array_b, push_count);
	if (push_count > 1)
	{
		split_stack(stack_a, stack_b, array, ft_lstsize(*stack_a));
		rev_split_stack(stack_a, stack_b, array_b, push_count);

	}
	else
	{
		if (ft_lstsize(*stack_a) == 2)
		{
			if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
				swap(stack_a, "sa");
		}
		push(stack_a, stack_b, "pa");
	}
	
}

void	rev_split_stack(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	middle;
	int	rb_count;
	int	push_count;
	int	*array_a;
	int	*array_b;
	
	middle = array[len / 2];
	rb_count = 0;
	push_count = 0;
	//printf_reverse(array, len);
//	ft_printf("len: %d\n", len);
	if (len == 1)
	{
		push(stack_a, stack_b, "pa");
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
		return ;
	}
	if (len == 2)
	{
		if (*((int *)(*stack_b)->content) < *((int *)(*stack_b)->next->content))
			swap(stack_b, "sb");
		push(stack_a, stack_b, "pa");
		push(stack_a, stack_b, "pa");
		return ;
	}
	while (rev_check_stack(*stack_b, middle))
	{
		if (*((int *)(*stack_b)->content) > middle)
		{
		//	ft_printf("cara: %d\n", *((int *)(*stack_b)->content));
			push(stack_a, stack_b, "pa");
			push_count++;
		}
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
	array_a = sort_array(*stack_a, push_count);
	if (push_count > 2)
		chunck_a(stack_a, stack_b, array_a, push_count);
	if (push_count == 2)
	{
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
	}
	if (len - push_count >= 2)
	{
		array_b = sort_array(*stack_b, len - push_count);
		rev_split_stack(stack_a, stack_b, array_b, len - push_count);
	}
}

void	chunck_a(t_list **stack_a, t_list **stack_b, int *array, int len)
{
	int	push_count;
	int	*array_b;
	int	*array_a;
	int middle;
	int	ra_count;
	int index;
	int limit;
	
	//ft_printf("chunck_a: ");
	//printf_reverse(array, len);
	middle = array[len / 2];
	ra_count = 0;
	push_count = 0;
	index = 0;
	limit = len - ((len - 1) - (len / 2));
	// if (len == 1)
	// {
	// 	push(stack_)
	// }
	while (check_stack(*stack_a, middle))
	{
		if (*((int *)(*stack_a)->content) < middle)
		{
			push(stack_b, stack_a, "pb");
			push_count++;
			index++;
		}
		else
		{
			rotate(stack_a, "ra");
		//	ft_printf("middle: %d, content: %d\n", middle, *((int *)(*stack_a)->content));
			ra_count++;
		}
	}
//	ft_printf("oiiiii\n");
	while (ra_count > 0)
	{
		reverse_rotate(stack_a, "rra");
		ra_count--;
	}
	if (len - push_count > 2)
	{
		array_a = sort_array(*stack_a, len - push_count);
		chunck_a(stack_a, stack_b, array_a, len - push_count);
	}
	//CHAMAR CHUNK A
	if (len - push_count == 2)
	{
		if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
			swap(stack_a, "sa");
	}
	//if (push_count >= 2)
	//{
		array_b = sort_array(*stack_b, push_count);
		rev_split_stack(stack_a, stack_b, array_b, push_count);
	//}
	// if (push_count == 1) // ou len-push_count > 2
	// {
	// 	array_a = sort_array(*stack_a, len - push_count);
	// 	chunck_a(stack_a, stack_b, array_a, len - push_count);
	// }
	// if (len - push_count > 2)
	// {
	// 	array_a = sort_array(*stack_a, len - push_count);
	// 	chunck_a(stack_a, stack_b, array_a, len - push_count);
	// }
	// else if (len - push_count == 2)
	// {
	// 	if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
 	// 	swap(stack_a, "sa");
	// }
	// if (push_count > 2)
	// {
	// 	array_b = sort_array(*stack_b, push_count);
	// 	rev_split_stack(stack_a, stack_b, array_b, push_count);
	// }
	// else if (push_count == 1)
	// {
	// 	if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
	// 		swap(stack_a, "sa");
	// }
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