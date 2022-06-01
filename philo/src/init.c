/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:07:17 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/27 20:09:50 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_init_parameters(t_data *data, int argc, char **argv)
{
	if (argc == 6 && argv[5][0])
		data->param.number_of_meals = ft_atoi (argv[5]);
	else
		data->param.number_of_meals = -1;
	data->param.nb = ft_atoi(argv[1]);
	data->param.tt_die = ft_atoi(argv[2]);
	data->param.tt_eat = ft_atoi(argv[3]);
	data->param.tt_sleep = ft_atoi(argv[4]);
}

t_data	*ft_init_data(int argc, char **argv)
{
	int				i;
	t_data			*data;
	struct timeval	start_time;

	i = -1;
	data = malloc(sizeof(t_data));
	ft_init_parameters(data, argc, argv);
	data->who_is_dead = -1;
	data->philo = malloc(sizeof(t_one_philo) * (data->param.nb));
	while (++i < data->param.nb)
	{		
		data->philo[i].thread = malloc(sizeof(pthread_t));
		data->philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philo[i].left_fork, NULL);
		data->philo[i].status_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philo[i].status_mutex, NULL);
		data->philo[i].has_finished = 0;
	}
	gettimeofday(&start_time, NULL);
	data->start_time = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (data);
}

void	ft_init_list(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb)
	{
		data->philo[i].id = i;
		data->philo[i].status = IS_ALIVE;
		if (i != data->param.nb - 1)
		{
			data->philo[i].next_philo = &data->philo[i + 1];
			data->philo[i].right_fork = data->philo[i + 1].left_fork;
		}
		else
		{
			data->philo[i].next_philo = &data->philo[0];
			data->philo[i].right_fork = data->philo[0].left_fork;
		}
		data->philo[i].start_time = data->start_time;
		data->philo[i].param = data->param;
		i ++;
	}
}
