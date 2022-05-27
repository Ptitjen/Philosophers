/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:13:55 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/27 12:19:36 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>
#include <stdint.h>
#include <sys/time.h>

int	main(int argc, char **argv)
{	
	t_data		*data;
	int			i;
	pthread_t	checker;

	i = 0;
	ft_arg_error(argc, argv);
	data = ft_init_data(argc, argv);
	ft_init_list(data);
	while (i < data->param.nb)
	{
		pthread_create(&data->philo[i].thread,
			NULL, ft_philosopher, &data->philo[i]);
		i ++;
	}
	i = 0;
	while (i < data->param.nb)
	{
		pthread_detach(data->philo[i].thread);
		i ++;
	}
	pthread_create(&checker, NULL, ft_check_is_dead, data);
	pthread_join(checker, 0);
	free(data);
	return (0);
}
