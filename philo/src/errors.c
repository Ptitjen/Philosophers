/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:39:36 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/25 16:41:19 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write (fd, &str[i], 1);
			i ++;
		}
	}
}

static void	ft_show_required_parameters(void)
{
	ft_putstr_fd("              ./philo usage :      \n\n", 2);
	ft_putstr_fd("      => \U0001F9D0 Number of philosophers \n", 2);
	ft_putstr_fd("      => \U0001F47B Time to die \n", 2);
	ft_putstr_fd("      => \U0001F35D Time to eat \n", 2);
	ft_putstr_fd("      => \U0001F634 Time to sleep \n", 2);
	ft_putstr_fd("      => Option : Number of meals \n", 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}

static int	ft_is_empty(char *str)
{
	if (str[0] == '\0')
	{
		ft_putstr_fd("\n    \U0001F6AB At least one argument is empty \U0001F6AB\n\n", 2);
		ft_show_required_parameters();
		exit (1);
	}
	return (1);
}

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_fd("\n    \U0001F6AB  At least one parameter is not a number \U0001F6AB\n\n", 2);
			ft_show_required_parameters();
			exit (1);
		}
		i ++;
	}
	if (i >= 9)
	{
		ft_putstr_fd("\n    \U0001F6AB  Don't you think one of the numbers is a little bit too big? \U0001F6AB   \n\n", 2);
		ft_show_required_parameters();
		exit (1);
	}
	return (1);
}

void	ft_arg_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (!(argc == 5 || argc == 6))
	{
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("    \U0001F6AB   Wrong number of arguments   \U0001F6AB   \n\n", 2);
		ft_show_required_parameters();
	}
	while (i < argc)
	{
		ft_is_number(argv[i]);
		if (i != 5)
			ft_is_empty(argv[i]);
		if (i != 5 && i != 4 && argv[i][0] == '0' && argv[i][1] == 0)
		{
			ft_putstr_fd("\n    \U0001F6AB  Some parameters cannot be 0 \U0001F6AB\n\n", 2);
			ft_show_required_parameters();
			exit (1);
		}
		i ++;
	}
}
