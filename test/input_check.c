/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:22 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:23 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!check_nbr(argv[i]))
		{
			if (argc == 2)
				error_handler(argv);
			else
				error_handler(0);
		}
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
		{
			if (argc == 2)
				error_handler(argv);
			else
				error_handler(0);
		}
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp_argv;
	char	**tmp_array;

	i = 0;
	if (argc == 2)
		tmp_array = ft_split(argv[1], ' ');
	else
		tmp_array = argv + 1;
	check_argv(argc, tmp_array);
	while (tmp_array[i])
	{
		tmp_argv = ft_atoi(tmp_array[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
			error_handler(tmp_array);
		if (check_doubles(tmp_array) && argc > 2)
			error_handler(0);
		if (check_doubles(tmp_array) && argc == 2)
			error_handler(tmp_array);
		if (!check_nbr(tmp_array[i]))
			error_handler(tmp_array);
		i++;
	}
	if (argc == 2)
		free_strs(tmp_array);
}

int	check_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (ft_isdigit(str[i]) || (str[i] == ' '
				|| str[i] == '-' || str[i] == '+')))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	else
		return (1);
}
