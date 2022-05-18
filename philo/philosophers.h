/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:42:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/17 15:29:43 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo_param {
	int nb;
	int ttd;
	int tte;
	int tts;
	int npe;
}   t_philo_param;

int	    ft_atoi(const char *str);
void    ft_arg_error(int argc, char **argv);
void	ft_putnbr_fd(int n, int fd);
void    ft_display_time(void);
#endif