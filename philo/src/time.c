/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:12:42 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/27 16:26:41 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long int	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_sleep(int sleep_time)
{
	long int	start_sleep_time;

	start_sleep_time = ft_get_time();
	usleep(sleep_time * 1000 * 0.90);
	while (ft_get_time() < (long int)sleep_time + start_sleep_time)
		usleep(5);
}
