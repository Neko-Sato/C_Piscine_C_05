/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:09:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/17 11:46:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_arry
{
	unsigned int	num;
	struct s_arry	*next;
}					t_arry;

int	explore_prime(t_arry *fast_prime, int last_num, int num)
{
	int		i;
	t_arry	*current_prime;
	t_arry	next_prime;

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
	if (next_prime.num == num)
		return (1);
	else if (next_prime.num > num)
		return (0);
	explore_prime(fast_prime, i, num);
}

int	ft_is_prime(int nb)
{
	t_arry	fast_prime;

	fast_prime.num = 2;
	fast_prime.next = (void *)0;
	return (explore_prime(&fast_prime, fast_prime.num, nb));
}

int	main(void)
{
	int	d;

	d = ft_is_prime(4);
}
