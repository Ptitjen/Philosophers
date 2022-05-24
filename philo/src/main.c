/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:13:55 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/24 17:07:14 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdint.h>
#include <sys/time.h>


int		ft_check_one_is_dead (t_data *data)
{
	int i = 0;
	while (i < data->param.nb)
	{
		//printf("Checking philo nb %d, status : %d\n", data->philo[i].num, data->philo[i].status);
		if (data->philo[i].status == IS_DEAD)
		{
			printf("%ld : %d died \U0001F47B\n", ft_get_time() - data->philo->start_time, i);
			//ft_died(data->philo[i]);	
			return (1);
		}
		i ++;		
	}
	return (0);
}

void    *ft_philosopher(void *arg){

	t_one_philo	*philo;

	philo = arg;
	philo->last_meal = ft_get_time();
	philo->nb_of_meals = 0;
		
	while (1)
	{
		if (philo->param.nom >= 0 && philo->nb_of_meals >= philo->param.nom)
		{		
			printf("%ld : %d has taken all his meals \U0001F922\n", ft_get_time() - philo->start_time, philo->num);
			pthread_join(philo->thread, 0);
			return(0);
		}	
	//	printf("Time before death for philo %d : %ld\n",  ft_time_before_dying(data));
		//left fork
		//pthread_mutex_init(philo->left_fork, NULL);
		pthread_mutex_lock(philo->left_fork);
		ft_has_taken_a_fork(philo);

		//right fork
		//philo->right_fork = philo->next_philo->left_fork;
		pthread_mutex_lock(philo->next_philo->left_fork);
		ft_has_taken_a_fork(philo);		

		//meal
		ft_is_eating(philo);
		philo->last_meal = ft_get_time();
		philo->nb_of_meals ++;

		//left fork
		pthread_mutex_unlock(philo->left_fork);

		//right fork
		pthread_mutex_unlock(philo->next_philo->left_fork);	

		pthread_mutex_unlock(philo->write_protector);	
		printf("%ld : %d has done eating meal number %d and put the forks back on the table \U0001F601\n", ft_get_time() - philo->start_time, philo->num, philo->nb_of_meals);
		pthread_mutex_unlock(philo->write_protector);
		
		if (philo->param.ttd - (ft_get_time() - philo->last_meal) <= 0)
		{
			philo->status = IS_DEAD;
			printf("%ld : %d died \U0001F47B\n", ft_get_time() - philo->start_time, philo->num);

			exit(0);
		}
		else 
			ft_is_thinking(philo);
	}	
	return(0);
}		



int main(int argc, char **argv)
{	
	t_data	*data;
	int		i;
		
	ft_arg_error(argc, argv);
	data = ft_init_data(argc, argv);
	i = 0;

	while (i < data->param.nb)	
	{
		data->philo[i].num = i;
		data->philo[i].status = IS_ALIVE;
		if (i != data->param.nb - 1)
			data->philo[i].next_philo = &data->philo[i + 1];
		else
			data->philo[i].next_philo = &data->philo[0];
		
		data->philo[i].start_time = data->start_time;
		data->philo[i].param = data->param;	
		i ++;
	}
	
	i = 0;
	while (i < data->param.nb && !ft_check_one_is_dead(data))
	{
		pthread_create (&data->philo[i].thread, NULL, ft_philosopher, &data->philo[i]);
		usleep(5);
		i ++;
	}
	i = -1;
	while (++i < data->param.nb)
		pthread_join(data->philo[i].thread, NULL);	
	return (0);
}


