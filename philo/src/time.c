/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:12:42 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/24 11:28:19 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

 long int	ft_get_time(void)
{
	 long int	time;
	struct timeval 		current_time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}

//a verifier?
void    ft_sleep(int sleep_time) //entree en ms
{
	 long int	start_sleep_time;

	start_sleep_time = ft_get_time();
	usleep(sleep_time * 1000 * 0.9); //argument en microsecondes
	while (ft_get_time() < ( long int)sleep_time + start_sleep_time)
		usleep(10); // pour reajuster le usleep :  a verif
}