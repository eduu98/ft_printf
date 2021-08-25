/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_various.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:23 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/06/14 17:13:16 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

/*
 * Print a string in the console
 * It wont print more characters than the precision given
 */
int	ft_putstr(char *s, int precision)
{
	int	chars;

	chars = 0;
	if (s)
	{
		while (*(s + chars) && (precision < 0 || chars < precision))
		{
			write(1, (s + chars), 1);
			chars++;
		}
	}
	return (chars);
}

/*
 * Print x number of character (used for spaces and zeros)
 * If nchar is negative it wont print anything
 */
int	ft_print_x_chars(int nchar, char c)
{
	int	aux;

	if (nchar > 0)
	{
		aux = nchar;
		while (aux)
		{
			ft_putchar_fd(c, 1);
			aux--;
		}
		return (nchar);
	}	
	return (0);
}

/*
 * Writes the long ’n’
 */
void	ft_putlongnbr(long n)
{
	if (n == 0)
		ft_putchar_fd('0', 1);
	else
	{
		if (n / 10 > 0)
			ft_putlongnbr(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
}
