/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:15:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/14 23:35:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define UNSARG 1
# define NOTDIGIT 2
# define INTOVER 3
# define EDUPLI 4
# define FALLOC 5
# define LESS 0
# define GREATER 1

void	get_args(t_list **stack_a, int argc, char *argv[]);
void	error_handle(int code);
void	swap(t_list **stack, char *id);
void	push(t_list **dest, t_list **src, char *id);
void	rotate(t_list **stack, char *id);
void	reverse_rotate(t_list **stack, char *id);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		*sort_array(t_list *stack, int length);
void	sort_stack(t_list **stack_a, t_list **stack_b, int *array, int len);
void	sort_chunk(t_list **stack_a, t_list **stack_b, int len);
void	r_sort_stack(t_list **stack_a, t_list **stack_b, int *array, int len);
int		r_len_checker(t_list **stack_a, t_list **stack_b, int len);
int		r_mid_point(t_list **stack_a, t_list **stack_b, int *array, int len);
int		r_check_stack(t_list *stack, int middle);
void	restore_stack(t_list **stack, int count, char *rule);
void	sort_chunk_a(t_list **stack_a, t_list **stack_b, int *array, int len);
int		mid_point_2(t_list **stack_a, t_list **stack_b, int *array, int len);
int		check_stack(t_list *stack, int middle, int op);
void	sort_chunk_2(t_list **stack_a, t_list **stack_b, int len, int count);
int		check_error(t_list **stack_a, t_list **stack_b, int *array);
int		create_node(t_list **stack_a, char *argv);
int		is_sorted(t_list *stack_a, t_list *stack_b);
int		check_len(t_list **stack_a, int len);

#endif
