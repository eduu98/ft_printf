/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:49 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/06/23 16:49:10 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"
/*
 * Getting the precision specified in the flags
 */
void	ft_get_precision (const char **format, t_flags *flags, va_list argp)
{
	format[0]++;
	if (ft_isdigit(**format))
	{
		flags->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			format[0]++;
		format[0]--;
	}
	else if (**format == '*')
		flags->precision = va_arg(argp, int);
	else
	{
		flags->precision = 0;
		format[0]--;
	}
	if (flags->zero == 1)
		flags->zero = 0;
}

/*
 * Getting the width specified in the flags
 */
void	ft_get_width (t_flags *flags, va_list argp)
{
	flags->width = va_arg(argp, int);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
	}
}

/*
 * Checking the flags introduced
 */
void	ft_checkflags(const char **format, t_flags *flags, va_list argp)
{
	while (!ft_strchr("cspdiuxX%", **format))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '.')
			ft_get_precision(format, flags, argp);
		else if (**format == '*')
			ft_get_width(flags, argp);
		else if (ft_isdigit(**format))
		{
			flags->width = ft_atoi(*format);
			while (ft_isdigit(**format))
				format[0]++;
			format[0]--;
		}
		format[0]++;
	}
}

/*
 * Cheking the format that goes after the character %
 */
void	ft_checkformat(const char **format, va_list argp,
	int *chars, t_flags *flags)
{
	if (**format == '%')
		*chars += ft_printchar('%', flags);
	else if (**format == 'c')
		*chars += ft_printchar(va_arg(argp, int), flags);
	else if (**format == 's')
		*chars += ft_printstr(va_arg(argp, char *), flags, 32);
	else if (**format == 'p')
		*chars += ft_printpoint(va_arg(argp, unsigned long), flags);
	else if (**format == 'd' || **format == 'i')
		*chars += ft_printnumber(va_arg(argp, int), flags);
	else if (**format == 'u')
		*chars += ft_printnumber(va_arg(argp, unsigned), flags);
	else if (**format == 'x' || **format == 'X')
		*chars += ft_printhexa(va_arg(argp, long), flags, **format);
}

/*
 * Replicate the functioning of the printf of the libc
 */
int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		characters;
	t_flags	flags;

	characters = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = (t_flags){0, 0, -1, 0};
			if (!ft_strchr("cspdiuxX%", *format))
				ft_checkflags(&format, &flags, argp);
			ft_checkformat(&format, argp, &characters, &flags);
		}
		else
			characters += write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(argp);
	return (characters);
}
