/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:47 by jisse             #+#    #+#             */
/*   Updated: 2023/01/18 20:40:11 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	backa(t_stacks *stack, int push)
{
	int i;
	
	i = 0;
	while (i < push)
	{
		rra(stack);
		i++;
	}
}

void	backb(t_stacks *stack, int push)
{
	int i;

	i = 0;
	while (i < push)
	{
		rrb(stack);
		i++;
	}
}

int	is_sorted(t_stack *stack, int end)
{
	int	i;
	if (end <= 1)
		return (1);
	i = 0;
	while (i < end)
	{
		if (stack->stack[stack->top - i] < stack->stack[stack->top - i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sortedb(t_stack *stack, int end)
{
	int i;
	if (end == 1)
		return (1);
	i = 0;
	while (i < end)
	{
		if (stack->stack[stack->top - i] > stack->stack[stack->top - i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	swapa_or_not(t_stacks *stack, int push)
{
	if (push <= 2)
	{
		if (stack->a.stack[stack->a.top] > stack->a.stack[stack->a.top - 1])
			sa(stack);
		return (1);
	}
	return (0);
}
int	swapb_or_not(t_stacks *stack, int push)
{
	if (push <= 2)
	{
		if (stack->b.stack[stack->b.top] < stack->b.stack[stack->b.top - 1])
			sb(stack);
		return (1);
	}
	return (0);
}

void	push_to_a(t_stacks *stack, int push)
{
	int	i;

	i = 0;
	while (i < push)
	{
		pa(stack);
		i++;
	}
	
}