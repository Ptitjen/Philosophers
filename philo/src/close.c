/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:52:19 by jenny             #+#    #+#             */
/*   Updated: 2022/05/27 14:25:22 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_close(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb)
	{
		if (data->philo[i].thread)
			pthread_join(data->philo[i].thread, 0);
		i ++;
	}
	free(data);
}
