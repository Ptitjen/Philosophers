/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:14:25 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/25 16:09:46 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//voir si on peut optimiser la prise des fourchettes?
void	ft_has_taken_a_fork(t_one_philo *philo)
{	
	if (philo->id % 2 == 0 && philo->next_philo->id != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->write_protector);
		printf("%ld : %d has taken a fork \U0001F944\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		printf("%ld : %d has taken a fork \U0001F374\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->write_protector);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->write_protector);
		printf("%ld : %d has taken a fork \U0001F944\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		printf("%ld : %d has taken a fork \U0001F374\n", \
				ft_get_time() - philo->start_time, philo->id + 1);
		pthread_mutex_unlock(philo->write_protector);
	}
}

void	ft_is_eating(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d is eating \U0001F35D\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->write_protector);
	philo->last_meal = ft_get_time();
	philo->nb_of_meals ++;
	if (philo->nb_of_meals == philo->param.number_of_meals)
		philo->status = HAS_FINISHED;
	ft_sleep(philo->param.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_is_sleeping(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d is sleeping \U0001F634\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->write_protector);
	ft_sleep(philo->param.time_to_sleep);
}

void	ft_is_thinking(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d is thinking \U0001F914\n", \
			ft_get_time() - philo->start_time, philo->id + 1);
	pthread_mutex_unlock(philo->write_protector);
}

