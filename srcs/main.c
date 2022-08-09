/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:14:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/09 15:10:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp_a; // just to visualize
	int		*sorted;
	t_list	*temp_b; // just to visualize

	stack_a = NULL;
	stack_b = NULL;
	//ft_putnbr_fd(argc - 1, 1);
	get_args(&stack_a, argc, argv);
	sorted = sort_array(stack_a, ft_lstsize(stack_a));
	split_stack(&stack_a, &stack_b, sorted, ft_lstsize(stack_a));
	// swap(&stack_a, "sa");
	// push(&stack_b, &stack_a, "pb");
	// push(&stack_b, &stack_a, "pb");
	// push(&stack_b, &stack_a, "pb");
	// rr(&stack_a, &stack_b);
	// rrr(&stack_a, &stack_b);
	// swap(&stack_a, "sa");
	// push(&stack_a, &stack_b, "pa");
	// push(&stack_a, &stack_b, "pa");
	// push(&stack_a, &stack_b, "pa");
	temp_a = stack_a;
	temp_b = stack_b;
	// while (temp_a != NULL)
	// {
	// 	ft_printf("valor_a: %i\n", *((int *)temp_a->content));
	// 	temp_a = temp_a->next;
	// }\
	// ft_putchar_fd('\n', 1);
	// while (temp_b != NULL)
	// {
	// 	ft_printf("valor_b: %d\n", *((int *)temp_b->content));
	// 	temp_b = temp_b->next;
	// }
	//ft_printf("\nnmemb_a: %d\n", ft_lstsize(stack_a));
	// int index = 0;
	// while (index < argc - 1)
	// {
	// 	ft_printf("%d\n", sorted[index]);
	// 	index++;
	// }
	// ft_printf("nmemb_b: %d\n", ft_lstsize(stack_b));
	ft_lstclear(&stack_a, free);
//	free(sorted);
	ft_lstclear(&stack_b, free);
	return (0);
}
