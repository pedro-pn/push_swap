/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:14:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/26 11:45:09 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;
	t_list	*temp_a; // just to visualize
	//t_list	*temp_b; // just to visualize

	stack_a = NULL;
//	stack_b = NULL;
	get_args(&stack_a, argc, argv);
	// swap(&stack_a);
	// swap(&stack_a);
//	rotate(&stack_a);
	reverse_rotate(&stack_a);
	// push(&stack_b, &stack_a);
	// push(&stack_b, &stack_a);
	temp_a = stack_a;
	// temp_b = stack_b;
	while (temp_a != NULL)
	{
		ft_printf("valor_a: %i\n", *((int *)temp_a->content));
		temp_a = temp_a->next;
	}
	// while (temp_b != NULL)
	// {
	// 	ft_printf("valor_b: %d\n", *((int *)temp_b->content));
	// 	temp_b = temp_b->next;
	// }
	ft_printf("nmemb_a: %d\n", ft_lstsize(stack_a));
	// ft_printf("nmemb_b: %d\n", ft_lstsize(stack_b));
	ft_lstclear(&stack_a, free);
	// ft_lstclear(&stack_b, free);
	return (0);
}
