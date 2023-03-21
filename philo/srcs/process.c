/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:18:29 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/05 22:18:29 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	count_of_meals(t_philo *philo)
{
	int	flag_enough;
	int	i;

	if (philo->total_nbr_meals != -1 \
		&& philo->total_nbr_meals_option > 0)
	{
		flag_enough = 1;
		i = -1;
		while (++i < philo->philo_nbr)
			if (philo[i].total_nbr_meals < philo->total_nbr_meals_option)
				flag_enough = 0;
		if (flag_enough == 1)
		{
			i = -1;
			while (i < philo[i].philo_nbr)
			{
				philo[i].stop = 1;
				//printf("i am here");
				i++;
			}
			return (1);
		}
	}
	return (0);

}

void	philo_death(t_philo *philo, int i)
{
	philo->input->philo_death = 1;
	pthread_mutex_lock(&philo->lock_print);
	printf("\033[1;31m");
	printf("%ld philosopher %d has died\n", ft_time() - philo->time_start,
		philo[i].philo_id + 1);
	printf("\033[0m");
	i = -1;
	while (i < philo[i].philo_nbr)
	{
		philo[i].stop = 1;
		i++;
	}
	// ft_free(philo->input);
	exit(0);
}

void	*ft_monitor(void *input)
{
	t_philo	*philo;
	long	time_now;
	int		i;

	philo = (t_philo *)input;
	i = 0;
	while (philo[i].stop == 0)
	{
		i = -1;
		while (++i < philo->philo_nbr)
		{
			time_now = ft_time();
			if (time_now - philo[i].time_of_last_meal > philo[i].limit_of_life)
			{
				philo_death(philo, i);
				pthread_mutex_unlock(&philo->lock_print);
				return (NULL);
			}
		}
		if (count_of_meals(philo) || philo->stop)
			return (NULL);
	}
	return (NULL);
}

void	*ft_process(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	philo->time_of_last_meal = ft_time();
	philo->time_start = ft_time();
	while(!philo->input->philo_death)
	{
		if (philo->input->philo_death || philo->stop || count_of_meals(philo))
			return (NULL);
		taking_forks(philo);
		if (philo->input->philo_death || philo->stop || count_of_meals(philo))
			return (NULL);
		eating(philo);
		if (philo->input->philo_death || philo->stop || count_of_meals(philo))
			return (NULL);
		sleeping(philo);
		if (philo->input->philo_death || philo->stop || count_of_meals(philo))
			return (NULL);
		thinking(philo);
		if (philo->input->philo_death || philo->stop || count_of_meals(philo))
			return (NULL);
	}
	return (NULL);
}
