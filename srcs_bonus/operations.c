/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:40:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/11 13:18:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **stack)
{
	void	*temp;

	if (ft_lstsize(*stack) < 1)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	push(t_list **dest, t_list **src)
{
	t_list	*temp;
	t_list	*node;
	int		*content;

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

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	while (temp->next)
	{
		swap(&temp);
		temp = temp->next;
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (ft_lstsize(*stack) < 2)
		return ;
	if (temp->next->next)
		reverse_rotate(&(temp->next));
	swap(&temp);
}
