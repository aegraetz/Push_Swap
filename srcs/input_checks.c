/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anniegraetz <anniegraetz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:42:05 by anniegraetz       #+#    #+#             */
/*   Updated: 2022/09/05 09:31:51 by anniegraetz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_num(char *argv);
static int	check_int(char *argv);
static int	seeing_double(char *argv, char **av, int i);
static int	invalid_input(int error);

int	input_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (check_num(argv[i]) != 0)
			return (invalid_input(1));
	}
	i = 0;
	while (argv[++i])
	{
		if (check_int(argv[i]) != 0)
			return (invalid_input(2));
	}
	i = 0;
	while (argv[++i])
	{
		if (seeing_double(argv[i], argv, i) != 0)
			return (invalid_input(3));
	}
	return (0);//if inputs are all appropriate return
}

static int	check_num(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '-')//disregard whether its a +ve or -ve num for now
			i++;
		if (!(argv [i] >= '0' && argv[i] <= '9'))//check that it only contains numbers
			return (-1);//if not then error
	}
	return (0);
}

static int	check_int(char *argv)
{
	long int	num;

	num = ft_atoi(argv);//convert to int
	if (num < -2147483647 || num > 2147483647)//check that it's not smaller or larger than possible for an int
		return (-1);//if it is then error
	return (0);
}

static int	seeing_double(char *argv, char **av, int i)
{
	long int	num;

	num = ft_atoi(argv);//convert to int
	while (av[i + 1])
	{
		if (num == ft_atoi(av[i + 1]))//if the converted ints are the same then there is a duplicate
			return (-1);//and that's an error
		i++;
	}
	return (0);
}

static int	invalid_input(int error)
{
	if (error == 1)
	{
		write(1, "ERROR: input contains non numeric character\n", 45);
		exit(1);
	}
	if (error == 2)
	{
		write(1, "ERROR: input contains element bigger than an int\n", 50);
		exit(1);
	}
	if (error == 3)
	{
		write(1, "ERROR: input contains duplicate characters\n", 44);
		exit(1);
	}
	return (-1);
}
