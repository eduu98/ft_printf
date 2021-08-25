#ifndef PRINTFLIB_H
# define PRINTFLIB_H

# include <stdarg.h>
# include <unistd.h>
# include "Libft/libft.h"
typedef struct s_flags
{
	int				minus;
	int				zero;
	int				precision;
	int				width;
}	t_flags;
int		ft_printf(const char *format, ...);
int		ft_printchar(char c, t_flags *flags);
int		ft_printstr(char *s, t_flags *flags, int c);
int		ft_printpoint(unsigned long pointer, t_flags *flags);
int		ft_printnumber(long number, t_flags *flags);
int		ft_printhexa(int number, t_flags *flags, char format);

void	ft_put_long_hex(unsigned long n, int printzerox,
			int zeros, int precision);
void	ft_put_hex(unsigned int n, char	*g_base);
void	ft_putlongnbr(long n);
int		ft_intlen(long n);
int		ft_hexalen(unsigned int n);
int		ft_hexalen_long(unsigned long n);
int		ft_putstr(char *s, int precision);
int		ft_print_x_chars(int nchar, char c);
#endif