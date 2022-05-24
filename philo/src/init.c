/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:07:17 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/24 16:25:58 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

t_data	*ft_init_data(int argc, char **argv)
{
	t_data 				*data;
	struct timeval 		start_time;

	data = malloc(sizeof(t_data));
	if (argc == 6)
		data->param.nom = ft_atoi (argv[5]);
	else 
		data->param.nom = -1; //pas de limite de nb de repas
	data->param.nb = ft_atoi (argv[1]);
	data->param.ttd = ft_atoi (argv[2]);
	data->param.tte = ft_atoi (argv[3]);
	data->param.tts = ft_atoi (argv[4]);
	data->philo = malloc(sizeof(t_one_philo) * (data->param.nb));

	int	i = -1;
	while (++i < data->param.nb)
	{
		data->philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philo[i].left_fork, NULL);		
		data->philo[i].right_fork = malloc(sizeof(pthread_mutex_t));
		data->philo[i].write_protector = malloc(sizeof(pthread_mutex_t));
	}
	gettimeofday(&start_time, NULL);
	data->start_time = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (data);
}