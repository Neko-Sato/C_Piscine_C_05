/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:47:48 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 17:44:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isplaceable(int bord[], int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (bord[x - i] == bord[x])
			return (0);
		if (bord[x - i] == bord[x] + i)
			return (0);
		if (bord[x - i] == bord[x] - i)
			return (0);
		i++;
	}
	return (1);
}

void	display(int bord[], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = '0' + bord[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	n_queen(int bord[], int *count, int n, int x)
{
	if (n == x)
	{
		(*count)++;
		display(bord, n);
		return ;
	}
	bord[x] = 0;
	while (bord[x] < n)
	{
		if (isplaceable(bord, x))
			n_queen(bord, count, n, x + 1);
		bord[x]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	bord[8];
	int	i;

	i = 0;
	while (i < 8)
		bord[i++] = 8;
	i = 0;
	n_queen(bord, &i, 8, 0);
	return (i);
}

int	main(void)
{
	ft_ten_queens_puzzle();
}
