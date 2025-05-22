#include "../includes/push_swap.h"

t_stack	*stack_new(int	value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_stack	*fill_stack_a(const char *str)
{
	int i;
	char **args;
	t_stack *a;

	args = ft_split(str, ' ');
	if (!args)
		return (NULL);
	a = NULL;
	i = 0;
	while (args[i])
	{
		stack_add_back(&a, stack_new(ft_atoi(args[i])));
		i++;
	}
	free_args(args);
	return (a);
}