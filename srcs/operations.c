/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:40:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/26 17:04:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *id)
{
	void	*temp;

	if (ft_lstsize(*stack) < 1)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (id)
		ft_printf("%s\n", id);
}

void	push(t_list **dest, t_list **src, char *id)
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
	if (id)
		ft_printf("%s\n", id);
}

void	rotate(t_list **stack, char *id)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		swap(&temp, NULL);
		temp = temp->next;
	}
	if (id)
		ft_printf("%s\n", id);
}

void	reverse_rotate(t_list **stack, char *id)
{
	t_list	*temp;

	temp = *stack;
	if (temp->next->next)
		reverse_rotate(&(temp->next), NULL);
	swap(&temp, NULL);
	if (id && !temp->next->next)
		ft_printf("%s\n", id);
}
