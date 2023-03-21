/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_failure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:02:20 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/15 21:02:20 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	ft_failure(int errorcode)
{
	if (errorcode == 1)
	{
		printf("\033[1;31m");
		printf("Invalid Number\n");
		printf("\033[0m");
	}
	else if (errorcode == 2)
	{
		printf("\033[1;31m");
		printf("Please check the number of arguments\n");
		printf("\033[0m");
	}
	else if (errorcode == 3)
	{
		printf("\033[1;31m");
		printf("Please check if the arguments are valid\n");
		printf("\033[0m");
	}
	else if (errorcode == 4)
	{
		printf("\033[1;31m");
		printf("1 philo means 1 fork...2 forks needed to eat\n");
		printf("\033[0m");
	}
	else if (errorcode == 5)
	{
		printf("\033[1;31m");
		printf("philo number shuld be more than 1\n");
		printf("\033[0m");
	}
	else if (errorcode == 6)
	{
		printf("\033[1;31m");
		printf("malloc error\n");
		printf("\033[0m");
	}
	else if (errorcode == 7)
	{
		printf("\033[1;31m");
		printf("thread create error\n");
		printf("\033[0m");
	}
	else if (errorcode == 8)
	{
		printf("\033[1;31m");
		printf("fork failed\n");
		printf("\033[0m");
	}
	exit (errorcode);
}