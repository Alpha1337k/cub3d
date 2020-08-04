/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 20:35:12 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:55:47 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char printval;

	if ((int)n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n /= -1;
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		printval = (n % 10) + 48;
		write(fd, &printval, 1);
	}
	else
	{
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		printval = (n % 10) + 48;
		write(fd, &printval, 1);
	}
}
