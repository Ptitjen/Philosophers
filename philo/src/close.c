/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:52:19 by jenny             #+#    #+#             */
/*   Updated: 2022/05/27 19:34:14 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//TODO : frees and push
void	ft_close(t_data *data, pthread_t checker)
{
	int	i;

	pthread_join(checker, 0);
	i = 0;
	while (i < data->param.nb)
	{
		pthread_detach(data->philo->thread);
		data->philo = data->philo->next_philo;
		i ++;
	}
	usleep(50);
	if (data->who_is_dead != -1)
		printf("%-6ld : %3d \U0001F47B died\n",
			ft_get_time() - data->start_time, data->who_is_dead + 1);
	else
	{
		printf("\n\U0001F929 *********************************** \U0001F929 \n");
		printf("%-6ld : They finished all their meals !\n", \
				ft_get_time() - data->start_time);
		printf("\U0001F929 *********************************** \U0001F929 \n\n");
	}
	free(data);
}
