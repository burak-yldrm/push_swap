#include "../Lib/push_swap.h"

void	sort_trion(t_a_stack **content, int count)
{
	while (in_line((*content), count, 0))
	{
		if (!((*content)->value > (*content)->next->value)
			&& (*content)->value > (*content)->next->next->value)
			reverse_rotate_a(content);
		else if ((*content)->value < (*content)->next->value
			&& (*content)->value > (*content)->next->next->value)
			reverse_rotate_a(content);
		else if ((*content)->value > (*content)->next->next->value)
			rotate_a(content);
		else if ((*content)->value < (*content)->next->next->value
			&& (*content)->value < (*content)->next->value)
			swap_a(content);
		else if ((*content)->value > (*content)->next->value)
			swap_a(content);
	}
}

void	kvintett(t_a_stack **a_stack, t_b_stack **b_stack)
{
	int	*arr;
	int	min;

	while (in_line((*a_stack), lstsize(*a_stack), 0))
	{
		arr = array_creator(*a_stack);
		min = array_min_index(arr, lstsize(*a_stack) - 1);
		if (min > 0 && min < 3)
			rotate_a(a_stack);
		if (min >= 3 && min <= 4)
			reverse_rotate_a(a_stack);
		if ((*a_stack)->value == arr[min]
			&& in_line((*a_stack), 5, 1))
			push_b(b_stack, a_stack);
		if ((lstsize(*a_stack) == 3))
		{
			sort_trion(a_stack, lstsize(*a_stack));
			push_a(a_stack, b_stack);
			push_a(a_stack, b_stack);
		}
		free(arr);
	}
	print_a_struct(*a_stack);
	// print_b_struct(*b_stack);
}
