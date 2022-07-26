/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:15:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/26 13:21:53 by ppaulo-d         ###   ########.fr       */
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
void	swap(t_list **stack);
void	push(t_list **dest, t_list **src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif