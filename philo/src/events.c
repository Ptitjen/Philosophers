/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:14:25 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/24 16:57:54 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	ft_has_taken_a_fork(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d has taken a fork \U0001F944\n", ft_get_time() - philo->start_time, philo->num);
	pthread_mutex_unlock(philo->write_protector);
}

void	ft_is_eating(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d is eating \U0001F35D\n", ft_get_time() - philo->start_time, philo->num);
	//ft_sleep(philo->param.tte);
	usleep(philo->param.tte * 1000);
	pthread_mutex_lock(philo->write_protector);
}

void	ft_is_sleeping(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d is sleeping \U0001F634\n", ft_get_time() - philo->start_time, philo->num);
	usleep(philo->param.tts * 1000);
	pthread_mutex_lock(philo->write_protector);
}

void	ft_is_thinking(t_one_philo *philo)
{
	pthread_mutex_lock(philo->write_protector);
	printf("%ld : %d is thinking \U0001F914\n", ft_get_time() - philo->start_time, philo->num);
	//pas de sleep
	pthread_mutex_lock(philo->write_protector);
}

void	ft_died(t_one_philo *philo)
{				
	//pthread_mutex_lock(philo->write_protector);
	int i;
	i = 0;
	/*
	while (i <= philo->param.nb)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next_philo;
		i ++;
	}*/
	
	printf("%ld : %d died \U0001F47B\n", ft_get_time() - philo->start_time, philo->num);
	//pthread_mutex_lock(philo->write_protector);
	exit(0);

}
