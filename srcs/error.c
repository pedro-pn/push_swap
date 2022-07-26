/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/26 13:27:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(int code)
{
	if (code == UNSARG)
		write(STDERR_FILENO, "Insuficient number of arguments\n", 32);
	else if (code == INTOVER)
		write(STDERR_FILENO, "Int overflow detected!\n", 23);
	else if (code == NOTDIGIT)
		write(STDERR_FILENO, "Only integers are valid!\n", 25);
	else if (code == EDUPLI)
		write(STDERR_FILENO, "Duplicates are not allowed!\n", 28);
	exit(EXIT_FAILURE);
}
