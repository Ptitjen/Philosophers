/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:12:42 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/25 11:49:25 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long int	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

//si probleme : ajouter usleep 5 dans while - modifier 0.95
void	ft_sleep(int sleep_time)
{
	long int	start_sleep_time;

	start_sleep_time = ft_get_time();
	usleep(sleep_time * 1000 * 0.95);
	while (ft_get_time() < (long int)sleep_time + start_sleep_time)
		;
}
