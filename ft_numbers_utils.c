/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:07 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/06/17 13:46:50 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

/*
 * Get the length of a integer
 */
int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/*
 * Get the length of a hexadecimal
 */
int	ft_hexalen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

/*
 * Get the length of a long hexadecimal
 */
int	ft_hexalen_long(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

/*
 * Print in console the long hexadecimal number given
 * if printzerox is 1, it will print first "0x" for pointers
 */
void	ft_put_long_hex(unsigned long n, int printzerox,
			int zeros, int precision)
{
	char	*g_base;

	g_base = "0123456789abcdef";
	if (printzerox)
	{
		write(1, "0", 1);
		write(1, "x", 1);
	}
	if (zeros > 0)
		ft_print_x_chars(zeros, 48);
	if (precision > 0 || precision < 0)
	{
		precision --;
		if (n >= 16)
		{
			ft_put_long_hex(n / 16, 0, 0, precision);
			write(1, g_base + (n % 16), 1);
		}
		else
			write(1, g_base + n, 1);
	}	
}

/*
 * Print in console the hexadecimal number given
 */
void	ft_put_hex(unsigned int n, char	*g_base)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, g_base);
		write(1, g_base + (n % 16), 1);
	}
	else
		write(1, g_base + n, 1);
}
