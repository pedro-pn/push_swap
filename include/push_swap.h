/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:15:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/26 17:00:58 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define UNSARG 1
# define NOTDIGIT 2
# define INTOVER 3
# define EDUPLI 4

void	get_args(t_list **stack_a, int argc, char *argv[]);
void	error_handle(int code);
void	swap(t_list **stack, char *id);
void	push(t_list **dest, t_list **src, char *id);
void	rotate(t_list **stack, char *id);
void	reverse_rotate(t_list **stack, char *id);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif