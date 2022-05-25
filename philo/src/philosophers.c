/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:28:53 by jenny             #+#    #+#             */
/*   Updated: 2022/05/25 22:28:05 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_everyone_has_finished(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb)
	{
		if (data->philo[i].status != HAS_FINISHED)
			return (0);
		i ++;
	}
	return (1);
}

void	*ft_check_is_dead(void *arg)
{
	t_data	*data;

	data = arg;
	while (!ft_everyone_has_finished(data))
	{	
		if (ft_get_time() - data->philo->last_meal > data->philo->param.tt_die)
		{
			data->philo->status = IS_DEAD;
			pthread_mutex_lock(data->write_protector);
			printf("%-6ld : %3d \U0001F47B died\n",
				ft_get_time() - data->philo->start_time, data->philo->id + 1);
			pthread_mutex_unlock(data->write_protector);
		}
		if (data->philo->status == IS_DEAD)
		{
			while (data->philo->next_philo->status != IS_DEAD)
			{
				data->philo->next_philo->status = HAS_TO_STOP;
				data->philo = data->philo->next_philo;
			}
			return (0);
		}
		data->philo = data->philo->next_philo;
	}
	return (0);
}

int	ft_stop_thread(t_one_philo *philo)
{
	if (ft_get_time() - philo->last_meal > philo->param.tt_die)
	{
		philo->status = IS_DEAD;
		return (1);
	}
	if (philo->status == HAS_FINISHED)
	{	
		pthread_mutex_lock(philo->write_protector);
		pthread_mutex_unlock(philo->write_protector);
		return (1);
	}
	if (philo->status == HAS_TO_STOP)
		return (1);
	return (0);
}

void	*ft_philosopher(void *arg)
{
	t_one_philo	*philo;

	philo = arg;
	philo->last_meal = ft_get_time();
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
