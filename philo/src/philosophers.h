/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:42:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/24 16:57:59 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/_pthread/_pthread_t.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_parameters {
	int nb;
	int ttd;
	int tte;
	int tts;
	int nom;
}   t_parameters;

# define IS_DEAD 0
# define IS_ALIVE 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define IS_OVER_EATING 5
# define IS_WAITING_ONE_FORK 6
# define HAS_NO_FORK 7


typedef struct s_one_philo t_one_philo; 

struct s_one_philo {
	long int		start_time;
	t_parameters 	param;
	pthread_t		thread;
	int				num;
	int 			nb_of_meals;
	long int		last_meal;
	int 			status;
	pthread_mutex_t	*write_protector;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	t_one_philo		*next_philo;
};

typedef struct s_data {
	long int		start_time;
	t_parameters 	param;
	int				*current_philo;
	t_one_philo		*philo;
	pthread_mutex_t *fork_mutex;	
} t_data;

int	    			ft_atoi(const char *str);

void    			ft_arg_error(int argc, char **argv);
t_data				*ft_init_data(int argc, char **argv);

void    			ft_sleep(int sleep_time);
long int			ft_get_time(void);

//void				ft_has_taken_a_fork(t_data *data);
void				ft_has_taken_a_fork(t_one_philo *philo);
void				ft_is_eating(t_one_philo *philo);
void				ft_is_sleeping(t_one_philo *philo);
void				ft_is_thinking(t_one_philo *philo);
void				ft_died(t_one_philo *philo);

#endif