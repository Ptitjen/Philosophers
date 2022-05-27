/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:28:53 by jenny             #+#    #+#             */
/*   Updated: 2022/05/27 14:46:50 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_everyone_has_finished(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb)
	{
		if (data->philo[i].status_mutex)
			pthread_mutex_lock(data->philo[i].status_mutex);
		if (data->philo[i].status != HAS_FINISHED)
		{
			if (data->philo[i].status_mutex)
				pthread_mutex_unlock(data->philo[i].status_mutex);
			return (0);
		}
		if (data->philo[i].status_mutex)
			pthread_mutex_unlock(data->philo[i].status_mutex);
		i ++;
	}
	return (1);
}

static int	ft_stop_thread(t_one_philo *philo)
{
	pthread_mutex_lock(philo->status_mutex);
	if (philo->status == IS_DEAD)
	{	
		pthread_mutex_unlock(philo->status_mutex);
		return (1);
	}
	if (philo->status == HAS_FINISHED)
	{	
		printf("%-6ld : %3d \U0001F929 has finished all his meals\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
		pthread_join(philo->thread, NULL);
		pthread_mutex_unlock(philo->status_mutex);
		return (1);
	}
	if (philo->status == HAS_TO_STOP)
	{
		pthread_mutex_unlock(philo->status_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->status_mutex);
	return (0);
}

void	ft_stop_everyone(t_one_philo *philo)
{
	while (philo->status != IS_DEAD)
	{
		pthread_mutex_lock(philo->status_mutex);
		pthread_detach(philo->thread);
		philo->status = HAS_TO_STOP;
		pthread_mutex_unlock(philo->status_mutex);
		philo = philo->next_philo;
	}
}

void	*ft_check_is_dead(void *arg)
{
	t_data	*data;

	data = arg;
	while (!ft_everyone_has_finished(data))
	{	
		pthread_mutex_lock(data->philo->status_mutex);
		if (ft_get_time() - data->philo->last_meal > data->philo->param.tt_die)
		{			
			data->philo->status = IS_DEAD;
			pthread_mutex_lock(data->write_protector);
			printf("%-6ld : %3d \U0001F47B died\n",
				ft_get_time() - data->philo->start_time, data->philo->id + 1);
			pthread_detach(data->philo->thread);
			pthread_mutex_unlock(data->write_protector);
			ft_stop_everyone(data->philo->next_philo);
			pthread_mutex_unlock(data->philo->status_mutex);
			return (0);
		}
		pthread_mutex_unlock(data->philo->status_mutex);
		data->philo = data->philo->next_philo;
	}
	return (0);
}

void	*ft_philosopher(void *arg)
{
	t_one_philo	*philo;

	philo = arg;
	pthread_mutex_lock(philo->status_mutex);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->status_mutex);
	philo->nb_of_meals = 0;
	while (1)
	{
		if (ft_stop_thread(philo))
			return (0);
		ft_has_taken_a_fork(philo);
		if (ft_stop_thread(philo))
			return (0);
		ft_is_eating(philo);
		if (ft_stop_thread(philo))
			return (0);
		ft_is_sleeping(philo);
		if (ft_stop_thread(philo))
			return (0);
		ft_is_thinking(philo);
	}
	return (0);
}
