/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:21:20 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/12 11:21:20 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "philo.h"

struct s_philo;

typedef struct s_input
{
	int				philo_nbr;
	int				philo_id;
	time_t			time_start;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_death;
	int				philo_nbr_meals;
	pthread_mutex_t	*forks;
	pthread_t		*thread_ids;
	pthread_mutex_t	lock_print;
	struct s_philo	*all_philos;
	
}				t_input;

typedef struct s_philo
{
	int		philo_id;
	int		total_nbr_meals;
	int		total_nbr_meals_option;
	time_t	time_of_last_meal;
	int		philo_nbr;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_sleep;
	time_t	limit_of_life;
	int		stop;
	time_t	time_start;
	pthread_mutex_t	lock_print;
	pthread_mutex_t *left_fork;
	pthread_mutex_t	*right_fork;
	struct s_input	*input;
}		t_philo;

long	ft_time(void);
int		ft_atoi(const char *str);
int		ft_is_digit(char *str);
void	ft_failure(int errorcode);
int	init_args(t_input *input, int ac, char **av);
void	init_mutex(t_input *input);
void	*ft_process(void *input);
void	*ft_monitor(void *input);
void	init_threads(t_input *input);
void	init_philosophers(t_input *input);
void	ft_free(t_input *input);
void	unlock_and_destroy_mutex(t_input *input);
void	end_threads(t_input *input);
int		count_of_meals(t_philo *philo);
void	philo_death(t_philo *philo, int i);
void	ft_usleep(int ms);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	taking_forks(t_philo *philo);
void	failure_and_free(int errorcode, t_input *input);

#endif