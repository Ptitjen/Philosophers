/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:39:36 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/24 15:39:44 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    ft_is_number(char *str)
{
    int i;

    i = 0;
    if (str[0] == '\0')
    {
        write (2, "At least one empty entry\n", 25);
        exit (1);
    }
    while(str[i] != '\0')
    {
        if (str[i] < '0'  || str[i] > '9')
        {
            write(2, "At least one entry is not a correct number\n", 43);
            exit (1);
        }
        i ++;
    }
    //ajouter verification limite haute
    return (1);
}

void    ft_arg_error(int argc, char **argv)
{
    int i;

    i = 1;
    if (!(argc == 5 || argc == 6))
    {
        write (2, "\n###\n\nPhilo usage :\n./philo NP TTD TTE TTS #option[nom]\n\n###\n\n", 62);
        write(2, "NP : number of philosophers\n", 28);
        write(2, "TTD : Time To Die\n", 18);
        write(2, "TTE : Time To Eat\n", 18);
        write(2, "TTS : Time To Sleep\n", 20);
        write(2, "nom : Number of times each Philosopher must Eat\n\n", 50);
        exit (1);
    }
    while (i < argc) 
    {     
        ft_is_number(argv[i]);
        i ++;
    }
}