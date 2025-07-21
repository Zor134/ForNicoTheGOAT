/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laudinot <laudinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:39:33 by laudinot          #+#    #+#             */
/*   Updated: 2025/04/27 18:01:46 by laudinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	char	c;
	int		compteur;

	compteur = 0;
	if (n > 9)
	{
		compteur += ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	compteur += ft_putchar(c);
	return (compteur);
}
