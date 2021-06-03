#include "push_swap.h"
#include <libc.h>

int	only_numbers(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (!ft_is_digit(number[i]) && number[i] != ' ')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_arg(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	i;

	i = 2;
	while (i != ac)
	{
		if (!only_numbers(av[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_push_swap(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	if (!check_arg(ac, av))
	{
		ft_printf("Error, check numbers.\n");
		return (ERROR);
	}
	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
		size++;
	}
	printf("Size = %d.\n", size);
	return (SUCCESS);
}

int main(int ac, char **av)
{
	if (ac <= 1)
		ft_printf("Not enough numbers... Try again.\n");
	else
		ft_push_swap(ac, av);
	char *s = malloc(245);
	(void)s;
	return (SUCCESS);
}