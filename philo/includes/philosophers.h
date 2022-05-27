/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:42:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/27 11:32:32 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
//# include <sys/_pthread/_pthread_mutex_t.h>
//# include <sys/_pthread/_pthread_t.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

# define IS_DEAD 0
# define IS_ALIVE 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define IS_OVER_EATING 5
# define IS_WAITING_ONE_FORK 6
# define HAS_FINISHED 7
# define HAS_TO_STOP 8

typedef struct s_one_philo	t_one_philo;

typedef struct s_parameters {
	int	nb;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	number_of_meals;
}	t_parameters;

struct s_one_philo {
	long int		start_time;
	t_parameters	param;
	pthread_t		thread;
	int				id;
	int				nb_of_meals;
	long int		last_meal;
	int				status;
	pthread_mutex_t	*status_mutex;
	pthread_mutex_t	*write_protector;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_one_philo		*next_philo;
};

typedef struct s_data {
	long int		start_time;
	t_parameters	param;
	int				*current_philo;
	t_one_philo		*philo;
	int				one_is_dead;
	pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	*write_protector;
}	t_data;

int			ft_atoi(const char *str);

void		ft_arg_error(int argc, char **argv);
t_data		*ft_init_data(int argc, char **argv);
void		ft_init_list(t_data *data);

void		ft_sleep(int sleep_time);
long int	ft_get_time(void);

void		*ft_philosopher(void *arg);
void		*ft_check_is_dead(void *arg);
int			ft_stop_thread(t_one_philo *philo);

void		ft_has_taken_a_fork(t_one_philo *philo);
void		ft_is_eating(t_one_philo *philo);
void		ft_is_sleeping(t_one_philo *philo);
void		ft_is_thinking(t_one_philo *philo);

void		ft_close(t_data *data);

#endif