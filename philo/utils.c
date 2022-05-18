/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:08:41 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/17 15:35:39 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_display_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	ft_putnbr_fd(current_time.tv_usec, 1);   
}

//printf("\nTime seconds: %ld, time ms: %d\n", current_time.tv_sec, current_time.tv_usec); 