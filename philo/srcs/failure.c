/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:13:09 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/05 20:13:09 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_failure(int errorcode)
{
	if (errorcode == 1)
	{
		printf("\033[1;31m");
		printf("Please check the number of arguments\n");
		printf("\033[0m");
	}
	else if (errorcode == 2)
	{
		printf("\033[1;31m");
		printf("Please check if the arguments are valid\n");
		printf("\033[0m");
	}
	else if (errorcode == 3)
	{
		printf("\033[1;31m");
		printf("Please check the number of philosophers\n");
		printf("\033[0m");
	}
	else if (errorcode == 4)
	{
		printf("\033[1;31m");
		printf("Please check the number of meals\n");
		printf("\033[0m");
	}
	else if (errorcode == 8)
	{
		printf("\033[1;31m");
		printf("malloc failed\n");
		printf("\033[0m");
	}
	else if (errorcode == 9)
	{
		printf("\033[1;31m");
		printf("Invalid Number\n");
		printf("\033[0m");
	}
	else if (errorcode == 10)
	{
		printf("\033[1;31m");
		printf("1 philo means 1 fork...2 forks needed to eat\n");
		printf("\033[0m");
	}
	exit(errorcode);
}

void failure_and_free(int errorcode, t_input *input)
{
	if (errorcode == 5)
	{
		printf("\033[1;31m");
		printf("Mutex initialization failed\n");
		printf("\033[0m");
	}
		else if (errorcode == 6)
	{
		free(input->forks);
		printf("\033[1;31m");
		printf("Thread creation failed\n");
		printf("\033[0m");
	}
		else if (errorcode == 7)
	{
		free(input->forks);
		free(input->all_philos);
		printf("\033[1;31m");
		printf("Thread join failed\n");
		printf("\033[0m");
	}
	exit(errorcode);
}