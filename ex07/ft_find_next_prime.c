/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:38:16 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 11:43:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	newtons_method_sqrt(double n, unsigned int precision)
{
	double	result;

	result = n / 2;
	while (precision--)
		result = result - result / 2 + n / (2 * result);
	return (result);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	end;

	if (nb < 2)
		return (0);
	end = newtons_method_sqrt(nb, 20);
	i = 2;
	while (i <= end)
		if (!(nb % i++))
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (!ft_is_prime(nb))
		while (!ft_is_prime(nb))
			nb++;
	return (nb);
}
