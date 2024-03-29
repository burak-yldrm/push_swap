#include "../Lib/push_swap.h"

void	rotate_a(t_a_stack **source, int option)
{
	t_a_stack	*temp;

	lstadd_back(source, lstnew((*source)->value), (*source)->index);
	temp = *source;
	*source = (*source)->next;
	free(temp);
	if (option == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_b_stack **source, int option)
{
	t_b_stack	*temp;

	lstadd_back(source, lstnew((*source)->value), (*source)->index);
	temp = *source;
	*source = (*source)->next;
	free(temp);
	if (option == 0)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_a_stack **a_stack, t_b_stack **b_stack)
{
	rotate_a(a_stack, 1);
	rotate_b(b_stack, 1);
	write(1, "rr\n", 3);
}
