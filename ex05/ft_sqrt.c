/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:32:00 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 11:28:18 by hshimizu         ###   ########.fr       */
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

int	ft_sqrt(int nb)
{
	int	d;

	if (nb < 1)
		d = 0;
	else
	{
		d = newtons_method_sqrt(nb, 20);
		if (d != nb / d || 0 != nb%d)
			d = 0;
	}
	return (d);
}
