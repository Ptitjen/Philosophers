/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:14:25 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/27 19:58:24 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_has_taken_a_fork(t_one_philo *philo)
{	
	if (philo->id % 2 == 0 && philo->next_philo->id != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->status_mutex);
		printf("%-6ld %3d has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		printf("%-6ld %3d has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->status_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->status_mutex);
		printf("%-6ld %3d has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		printf("%-6ld %3d has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->status_mutex);
	}
}

void	ft_is_eating(t_one_philo *philo)
{
	pthread_mutex_lock(philo->status_mutex);
	printf("%-6ld %3d is eating\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	philo->last_meal = ft_get_time();
	philo->nb_of_meals ++;
	philo->status = IS_EATING;
	pthread_mutex_unlock(philo->status_mutex);
	ft_sleep(philo->param.tt_eat);
	pthread_mutex_lock(philo->status_mutex);
	if (philo->nb_of_meals == philo->param.number_of_meals)
		philo->has_finished = 1;
	else
		philo->status = IS_ALIVE;
	pthread_mutex_unlock(philo->status_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_is_sleeping(t_one_philo *philo)
{	
	pthread_mutex_lock(philo->status_mutex);
	printf("%-6ld %3d is sleeping\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->status_mutex);
	ft_sleep(philo->param.tt_sleep);
}

void	ft_is_thinking(t_one_philo *philo)
{
	pthread_mutex_lock(philo->status_mutex);
	printf("%-6ld %3d is thinking\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->status_mutex);
}
