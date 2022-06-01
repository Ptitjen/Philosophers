/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:52:19 by jenny             #+#    #+#             */
/*   Updated: 2022/05/27 19:34:14 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_stop_threads_and_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb)
	{
		pthread_detach(*data->philo->thread);
		pthread_mutex_destroy(data->philo->status_mutex);
		pthread_mutex_destroy(data->philo->left_fork);
		data->philo = data->philo->next_philo;
		i ++;
	}
}

static void	ft_print_end(t_data *data)
{
	if (data->who_is_dead != -1)
		printf("%-6ld %3d died\n",
			ft_get_time() - data->start_time, data->who_is_dead + 1);
	else
	{
		printf("\n\U0001F929 *********************************** \U0001F929 \n");
		printf("%-6ld : They finished all their meals !\n", \
				ft_get_time() - data->start_time);
		printf("\U0001F929 *********************************** \U0001F929 \n\n");
	}
}

static void	ft_free_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb)
	{
		free(data->philo->status_mutex);
		free(data->philo->left_fork);
		free(data->philo->thread);
		data->philo = data->philo->next_philo;
		i ++;
	}
}

void	ft_close(t_data *data, pthread_t *checker)
{
	pthread_join(*checker, 0);
	free(checker);
	ft_stop_threads_and_mutexes(data);
	usleep(50);
	ft_print_end(data);
	ft_free_philos(data);
	free(data->philo);
	free(data);
}
