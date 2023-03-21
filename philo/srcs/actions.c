/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:22:57 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/11 20:22:57 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	taking_forks_odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->lock_print);
	if (philo->stop != 1)
	{
		printf("\033[1;32m");
		printf( "%ld philosopher %d has taken the fork\n", ft_time() - philo->time_start, philo->philo_id + 1);
		printf("\033[1;32m");
		printf("%ld philosopher %d has taken the fork\n", ft_time() - philo->time_start, philo->philo_id + 1);
		printf("\033[0m");
	}
	pthread_mutex_unlock(&philo->lock_print);
}

void	taking_forks(t_philo *philo)
{
	if ((philo->philo_id) % 2 == 0 && philo->philo_id + 1 != philo->philo_nbr)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->lock_print);
		if (philo->stop != 1)
		{
			printf("\033[1;33m");
			printf("%ld philosopher %d has taken the fork\n", ft_time() - philo->time_start, philo->philo_id + 1);
			printf("\033[1;33m");
			printf("%ld philosopher %d has taken the fork\n", \
				 ft_time() - philo->time_start, philo->philo_id + 1);
			printf("\033[0m");
		}
		pthread_mutex_unlock(&philo->lock_print);
	}
	else
		taking_forks_odd_philo(philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("\033[1;36m");
	printf("%ld philosopher %d is eating\n", ft_time() - philo->time_start, philo->philo_id + 1);
	printf("\033[0m");
	pthread_mutex_unlock(&philo->lock_print);
	philo->total_nbr_meals += 1;
	philo->time_of_last_meal = ft_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("\033[1;35m");
	printf("%ld philosopher %d is sleeping\n", ft_time() - philo->time_start, philo->philo_id + 1);
	printf("\033[0m");
	pthread_mutex_unlock(&philo->lock_print);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf("\033[1;38m");
	printf("%ld philosopher %d is thinking\n", ft_time() - philo->time_start, philo->philo_id + 1);
	printf("\033[0m");
	pthread_mutex_unlock(&philo->lock_print);
}
