/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:14:25 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/25 22:25:14 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_has_taken_a_fork(t_one_philo *philo)
{	
	if (philo->id % 2 == 0 && philo->next_philo->id != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->write_protector);
		printf("%-6ld : %3d \U0001F944 has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		printf("%-6ld : %3d \U0001F374 has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->write_protector);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->write_protector);
		printf("%-6ld : %3d \U0001F944 has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		printf("%-6ld : %3d \U0001F374 has taken a fork\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->write_protector);
	}
}

void	ft_is_eating(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%-6ld : %3d \U0001F35D is eating\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->write_protector);
	philo->last_meal = ft_get_time();
	philo->nb_of_meals ++;
	if (philo->nb_of_meals == philo->param.number_of_meals)
		philo->status = HAS_FINISHED;
	ft_sleep(philo->param.tt_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_is_sleeping(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%-6ld : %3d \U0001F634 is sleeping\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->write_protector);
	ft_sleep(philo->param.tt_sleep);
}

void	ft_is_thinking(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%-6ld : %3d \U0001F914 is thinking\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->write_protector);
}