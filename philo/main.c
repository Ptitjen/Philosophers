/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:13:55 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/17 15:35:28 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *ft_philosopher(void *arg){

	int *n;
	n = arg;
	/*while (1)
	{*/

		ft_display_time();
		write (1, " : Philosopher ", 15);
		ft_putnbr_fd(*n, 1);
		write (1, " ", 1);
		write(1, " \n", 2);
  /*  }*/
	return(0);
}

t_philo_param   ft_init_params(int argc, char **argv)
{
	t_philo_param   p;
	if (argc == 6)
		p.npe = ft_atoi (argv[5]);
	else 
		p.npe = 1;
	p.nb = ft_atoi (argv[1]);
	p.ttd = ft_atoi (argv[2]);
	p.tte = ft_atoi (argv[3]);
	p.tts = ft_atoi (argv[4]);
	return (p);    
}

int main(int argc, char **argv)
{
	t_philo_param p;    
	pthread_t *philosophers_list;
	pthread_mutex_t mutex; 
	//pthread_attr_t *attr1;
	
	ft_arg_error(argc, argv);
	p = ft_init_params(argc, argv);
	pthread_mutex_init(&mutex, NULL); 
	pthread_mutex_lock(&mutex); 
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
   // printf("nb : %d, ttd : %d, tte : %d, tts : %d, npe : %d", p.nb, p.ttd, p.tte, p.tts, p.npe);
   
	philosophers_list = malloc(sizeof(pthread_t) * (p.nb + 1));
	int i = -1;
	while (++i < p.nb){
		pthread_create (&philosophers_list[i], NULL, ft_philosopher, (void*)&i);
		usleep(1000); 
	}
	i = -1;
	while (++i < p.nb){
		int rtn = pthread_join(philosophers_list[i], NULL);
		if (!rtn) {
			printf("Mort du philosophe %d [%u]\n", i, (int)philosophers_list[i]);
		}
	}
  
	return (0);
}
/*
Une variable globale partagée x peut être protégée par un mutex comme suit :


	int x;
	pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

Tous les accès et modifications de x doivent être entourés de paires d'appels à pthread_mutex_lock() et pthread_mutex_unlock() comme suit :


	pthread_mutex_lock(&mut);
	// agir sur x
	pthread_mutex_unlock(&mut);
*/


