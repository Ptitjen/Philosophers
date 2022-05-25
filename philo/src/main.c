/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:13:55 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/25 16:42:13 by jenny            ###   ########.fr       */
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
	pthread_create(&checker, NULL, ft_check_is_dead, data);
	pthread_join(checker, 0);
	ft_close(data);
	return (0);
}