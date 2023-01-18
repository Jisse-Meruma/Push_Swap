/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:32:40 by jmeruma           #+#    #+#             */
/*   Updated: 2023/01/18 19:05:16 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valid_digit(char *digit, t_stacks *stack)
{
	int	i;

	i = 0;
	if (digit[0] == '-') // only - breaks code..
		i++;
	while (digit[i])
	{
		if (ft_isdigit(digit[i]) == 0)
			error_exit(3, stack);
		i++;
	}
}
void	sorting(t_stacks *stack, int index, int end)
{
	int temp;
	int flag;
	
	flag = 1;
	while (index < end - 1)
	{
		if (stack->sorted[index] >= stack->sorted[index + 1])
		{
			if (stack->sorted[index] == stack->sorted[index + 1])
				error_exit(4, stack);
			temp = stack->sorted[index];
			stack->sorted[index] = stack->sorted[index + 1];
			stack->sorted[index + 1] = temp;
			flag = 0;
		}
		index++;
		if (flag == 0)
		{
			index = 0;
			flag = 1;
		}
	}
}

int	pivot_finder(t_stacks *main, t_stack *stack, int end)
{
	int pivot;

	main->sorted = malloc(end * sizeof(int));
	if (!main->sorted)
		error_exit(3, main);
	ft_memcpy(main->sorted, stack->stack + ((stack->top + 1) - end), end * sizeof(int));
	sorting(main, 0, end);
	pivot = main->sorted[end / 2];
	free(main->sorted);
	return (pivot);
}

void	int_assembly(t_stacks *stack, char *argv[])
{
	long	numb;
	int		i;
	int		index;
	
	index = 0;
	i = stack->total - 1;
	while (i >= 0)
	{
		valid_digit(argv[i], stack);
		numb = ft_latoi(argv[i]);
		if (!(numb <= INT_MAX && numb >= INT_MIN) || ft_strlen(argv[i]) == 0)
			error_exit(3, stack);
		stack->a.stack[index] = (int)numb;
		i--;
		index++;
	}
	stack->a.top = stack->total - 1;
	stack->b.top = -1;
}
