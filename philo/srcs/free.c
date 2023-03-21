/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:47:43 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/11 19:47:43 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free(t_input *input)
{
	free(input->thread_ids);
	free(input->all_philos);
	free(input->forks);
}

void	unlock_and_destroy_mutex(t_input *input)
{
	int philo_nbr;

	philo_nbr = input->philo_nbr;
	while(philo_nbr--)
	{
		pthread_mutex_unlock(&input->forks[philo_nbr]);
		pthread_mutex_destroy(&input->forks[philo_nbr]);
	}
	pthread_mutex_unlock(&(*input).lock_print);
	pthread_mutex_destroy(&(*input).lock_print);	
}

void	end_threads(t_input *input)
{
	int	philo_nbr;

	philo_nbr = input->philo_nbr;
	if (philo_nbr == 1)
		pthread_mutex_unlock(&input->forks[0]);
	while (philo_nbr)
	{
		philo_nbr--;
		pthread_join(input->thread_ids[philo_nbr], NULL);
	}
}