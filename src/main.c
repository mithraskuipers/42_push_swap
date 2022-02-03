#include "push_swap/push_swap.h"
#include "stack_list/push_swap_stack.h"
#include "../libft/libft.h"

static void valid_input(char *s);
static void init_stack(char **argv, t_stack *stack);
static t_stack	*ft_lstnew2(int index, int value);
static void	ft_lstadd_back2(t_stack **lst, t_stack *new);
static t_stack	*ft_lstlast2(t_stack *lst);
static int	ft_lstsize2(t_stack *lst);

#include <stdio.h>

void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		printf("List a NULL\n\n");
	else
	{
		printf("List a:\n");
		while (stack_a->next)
		{
			printf("%d=%d\n", stack_a->index, stack_a->value);
			stack_a = stack_a->next;
		}
		printf("%d=%d\n\n", stack_a->index, stack_a->value);
	}
	if (!stack_b)
		printf("List b NULL\n");
	else
	{
		printf("List b:\n");
		while (stack_b->next)
		{
			printf("%d=%d\n", stack_b->index, stack_b->value);
			stack_b = stack_b->next;
		}
		printf("%d=%d\n", stack_b->index, stack_b->value);
	}
	printf("\n---\n\n");
}

int		main(int argc, char **argv)
{
	int		nbrs;
	t_stack *a;
	t_stack *b;

	nbrs = 0;
	if (argc < 1)
		return (0);
	init_stack(argv, NULL);
	return (0);
}

// niet static want ga ik waarschijnlijk vaker gebruiken
void reterror(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void valid_input(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
			reterror();
		if (s[i] == '-' && !ft_isdigit(s[i+1]))
			reterror();
		i++;
	}
}

static t_stack init_stack(char **argv, t_stack *stack)
{
	int	i;
	int j;
	char **split;

	i = 1;
	while (argv[i])//./program "2 6 3 4" 1 7 12 11 "10 9"
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit (EXIT_FAILURE);
		j = 0;
		while (split[j])
		{
			valid_input(split[j]);
			ft_lstadd_back2(&stack, ft_lstnew2(ft_lstsize2(stack), ft_atoi(split[j])));
			j++;
		}
		i++;
	}
	return (stack);
	//print_list(stack, 0); // rowan linked list printer
	//while(1); //
}

static t_stack	*ft_lstnew2(int index, int value)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!(new_elem))
		return (NULL);
	new_elem->index = index;
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}

static void	ft_lstadd_back2(t_stack **lst, t_stack *new)
{
	t_stack	*final_element;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	final_element = ft_lstlast2(*lst);
	final_element->next = new;

}

static t_stack	*ft_lstlast2(t_stack *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static int	ft_lstsize2(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}













//static void	parse_numbers(int argc, char **argv);
//static char	**dp_clean(char **dp);

/*
static void	parse_numbers(int argc, char **argv)
{
	int	i;
	char	**numbers;
	i = 0;

	numbers = ft_split(argv[i], ' ');


	//dp_clean(numbers);
}

static char	**dp_clean(char **dp)
{
	int	i;

	i = 0;
	while ((dp[i]) && dp)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
	return (NULL);
}
*/