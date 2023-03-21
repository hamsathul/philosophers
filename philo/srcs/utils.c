/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:24:01 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/03/12 11:24:01 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

// The function first gets the current time using the
//  ft_time() function. It then uses the usleep() function
//  to sleep for ms * 920 microseconds 
//  (1 millisecond = 1000 microseconds),
//  which is approximately ms milliseconds.
// After the initial sleep, the function enters a 
// loop that continues sleeping for ms * 3 microseconds 
// until the elapsed time since the initial sleep is 
// greater than or equal to ms milliseconds. This loop is
// included to ensure that the function sleeps for at 
// least ms milliseconds, as the initial sleep may not be 
// precise.
void	ft_usleep(int ms)
{
	long	time;

	time = ft_time();
	usleep(ms * 920);
	while (ft_time() < (time + ms))
		usleep(ms * 3);
}

int	ft_atoi(const char *str)
{
	long	res;
	long	i;

	res = 0;
	i = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
		if (res * i > 2147483647)
			ft_failure(9);
		else if (res * i < -2147483648)
			ft_failure(9);
	}
	return (int)(res * i);
}

int	ft_is_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
