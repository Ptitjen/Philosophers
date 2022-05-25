/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:52:19 by jenny             #+#    #+#             */
/*   Updated: 2022/05/25 22:21:53 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_close(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->param.nb)
	{
		free(data->philo[i].left_fork);
		free(data->philo[i].write_protector);
	}
	free(data->write_protector);
	free(data);
}
