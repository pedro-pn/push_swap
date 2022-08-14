/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:40:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 00:47:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements of the stack.*/
void	swap(t_list **stack, char *id)
{
	void	*temp;

	if (id)
		ft_printf("%s\n", id);
	if (ft_lstsize(*stack) < 1)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

/* Passes the first element of the stack dest to the stack b.*/
void	push(t_list **dest, t_list **src, char *id)
{
	t_list	*temp;
	t_list	*node;
	int		*content;

	if (id)
		ft_printf("%s\n", id);
	if (!*src)
		return ;
	content = malloc(sizeof(*content));
	*content = *((int *)(*src)->content);
	node = ft_lstnew(content);
	if (*dest == NULL)
		*dest = node;
	else
		ft_lstadd_front(dest, node);
	temp = (*src);
	(*src) = (*src)->next;
	ft_lstdelone(temp, free);
}

/* Shifts all elements of the stack up. That means the first element ends up as
the last one.*/
void	rotate(t_list **stack, char *id)
{
	t_list	*temp;

	if (id)
		ft_printf("%s\n", id);
	if (!*stack)
		return ;
	temp = *stack;
	while (temp->next)
	{
		swap(&temp, NULL);
		temp = temp->next;
	}
}

/* Shifts all elements of the stack down. That means the last element ends up
as the first one.*/
void	reverse_rotate(t_list **stack, char *id)
{
	t_list	*temp;

	temp = *stack;
	if (id)
		ft_printf("%s\n", id);
	if (ft_lstsize(*stack) < 2)
		return ;
	if (temp->next->next)
		reverse_rotate(&(temp->next), NULL);
	swap(&temp, NULL);
}
