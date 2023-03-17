/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:09:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/17 13:14:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_arry
{
	unsigned int	num;
	struct s_arry	*next;
}					t_arry;

int	explore_prime(t_arry *fast_prime, unsigned last_num, unsigned int num)
{
	unsigned int	i;
	t_arry			*current_prime;
	t_arry			next_prime;

	i = last_num + 1;
	next_prime.next = (void *)0;
	current_prime = fast_prime;
	while ((*current_prime).next)
	{
		if (!(i % (*current_prime).num))
		{
			current_prime = fast_prime;
			i++;
		}
		current_prime = (*current_prime).next;
	}
	next_prime.num = i;
	(*current_prime).next = &next_prime;
	if (i == num)
		return (1);
	else if (i > num)
		return (0);
	return (explore_prime(fast_prime, i, num));
}

int	ft_is_prime(int nb)
{
	t_arry	fast_prime;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	else
	{
		fast_prime.num = 2;
		fast_prime.next = (void *)0;
		return (explore_prime(&fast_prime, fast_prime.num, nb));
	}
}


#include <stdio.h>

int	main(void)
{
	int	d;

	// for (int i = 0; i < ; i++)
	// 	if ()
			printf("%d, ", ft_is_prime(49));
}
