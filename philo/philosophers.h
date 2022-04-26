/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:42:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/26 17:42:21 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo_param {
    int nb;
    int ttd;
    int tte;
    int tts;
    int npe;
}   t_philo_param;

int	    ft_atoi(const char *str);
void    ft_arg_error(int argc, char **argv);
#endif