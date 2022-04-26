/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:13:55 by jeulliot          #+#    #+#             */
/*   Updated: 2022/04/26 17:13:57 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include<stdio.h>
t_philo_param   ft_init_params(int argc, char **argv)
{
    t_philo_param   p;
    if (argc == 6)
        p.npe = ft_atoi (argv[5]);
    else 
        p.npe = 1;
    p.nb = ft_atoi (argv[1]);
    p.ttd = ft_atoi (argv[2]);
    p.tte = ft_atoi (argv[3]);
    p.tts = ft_atoi (argv[4]);
    return (p);    
}

int main(int argc, char **argv)
{
    t_philo_param p;

    ft_arg_error(argc, argv);
    p = ft_init_params(argc, argv);
    printf("nb : %d, ttd : %d, tte : %d, tts : %d, npe : %d", p.nb, p.ttd, p.tte, p.tts, p.npe);
    return (0);
}