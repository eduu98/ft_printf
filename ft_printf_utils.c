/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:56:15 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/06/23 16:49:24 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

/*
 * Print a character in the console with the flags given
 */
int	ft_printchar(char c, t_flags *flags)
{
	int	chars;

	chars = 0;
	flags->width--;
	if (flags->width > 0)
	{
		if (flags->minus)
			chars += write(1, &c, 1);
		if (flags->zero && !flags->minus)
			chars += ft_print_x_chars(flags->width, 48);
		else
			chars += ft_print_x_chars(flags->width, 32);
		if (!flags->minus)
			chars += write(1, &c, 1);
	}
	else
		chars += write(1, &c, 1);
	return (chars);
}

/*
 * Print the string in the first parameter in the console with the flags given
 */
int	ft_printstr(char *s, t_flags *flags, int c)
{
	int	chars;
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags->precision > len)
		flags->precision = len;
	chars = 0;
	if (flags->width < 0 || (len > flags->width && flags->precision < 0))
		chars = ft_putstr(s, flags->precision);
	else
	{
		if (flags->zero && !flags->minus)
			c = 48;
		if (flags->minus)
			chars += ft_putstr(s, flags->precision);
		if (flags->precision >= 0)
			chars += ft_print_x_chars(flags->width - flags->precision, c);
		else
			chars += ft_print_x_chars(flags->width - len, c);
		if (!flags->minus)
			chars += ft_putstr(s, flags->precision);
	}
	return (chars);
}

/*
 * Print a pointer in the console with the flags given
 */
int	ft_printpoint(unsigned long p, t_flags *flags)
{
	int	chars;
	int	len;

	len = ft_hexalen_long(p);
	chars = 2;
	if (flags->precision < len && flags->precision != 0)
		flags->precision = len;
	if (flags->width < 0 || ((len + 2) > flags->width && flags->precision < 0))
	{
		ft_put_long_hex(p, 1, flags->precision - len, flags->precision);
	}
	else
	{
		if (flags->minus)
			ft_put_long_hex(p, 1, flags->precision - len, flags->precision);
		if (flags->precision >= 0)
			chars += ft_print_x_chars(flags->width - flags->precision - 2, 32);
		else
			chars += ft_print_x_chars(flags->width - len, 32);
		if (!flags->minus)
			ft_put_long_hex(p, 1, flags->precision - len, flags->precision);
	}
	chars += flags->precision;
	return (chars);
}

/*
 * Print a number in the console with the flags given
 */
int	ft_printnumber(long number, t_flags *flags)
{
	int	chars;
	int	len;

	if (flags->precision == 0 && number == 0)
		return (ft_print_x_chars(flags->width, 32));
	len = ft_intlen(number);
	chars = len;
	if (flags->precision < len)
		flags->precision = len;
	if (number < 0)
		flags->width--;
	if (!flags->minus && flags->zero)
		flags->precision = flags->width;
	if (!flags->minus)
		chars += ft_print_x_chars(flags->width - flags->precision, 32);
	if (number < 0)
	{
		chars += write(1, "-", 1);
		number *= -1;
	}	
	chars += ft_print_x_chars(flags->precision - len, 48);
	ft_putlongnbr(number);
	if (flags->minus)
		chars += ft_print_x_chars(flags->width - flags->precision, 32);
	return (chars);
}

/*
 * Print a number in the console with the flags given
 */
int	ft_printhexa(int number, t_flags *flags, char format)
{
	int	chars;
	int	len;

	if (flags->precision == 0 && number == 0)
		return (ft_print_x_chars(flags->width, 32));
	len = ft_hexalen(number);
	chars = len;
	if (flags->precision < len)
		flags->precision = len;
	if (!flags->minus && flags->zero)
		flags->precision = flags->width;
	if (!flags->minus)
		chars += ft_print_x_chars(flags->width - flags->precision, 32);
	chars += ft_print_x_chars(flags->precision - len, 48);
	if (format == 'X')
		ft_put_hex(number, "0123456789ABCDEF");
	else
		ft_put_hex(number, "0123456789abcdef");
	if (flags->minus)
		chars += ft_print_x_chars(flags->width - flags->precision, 32);
	return (chars);
}
