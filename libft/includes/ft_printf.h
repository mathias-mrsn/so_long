/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:53:58 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 13:55:35 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"
# define CONV_POSSIBLE "cspdiuxX%"
# define FLAGS "+ #-0"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_options
{
	char	conversion;

	int		flag_plus;
	int		flag_space;
	int		flag_hashtag;
	int		flag_dot;
	int		flag_zero;
	int		flag_align;
	int		precision_value;
	int		width;
	int		arg_length;
	int		printed_length;
}				t_options;

typedef struct s_argument
{
	char		arg_c;
	char		*arg_s;
	long long	arg;
	char		*base_used;
}				t_argument;

int		__printf(const char *str, ...);

/* PARSING */

void	ft_parse_hub(t_options *options, const char **str,
			va_list settings, t_argument *arg);
int		ft_get_convert(t_options *options, const char **str);
int		ft_get_flags(t_options *options, const char **str, va_list settings);
void	ft_get_precision(t_options *options,
			const char **str, va_list settings);

/* PRINT FUNCTIONS */

void	ft_print_hub(t_options *options, t_argument *arg);
void	ft_print_blank(t_options *options, t_argument *arg);
void	ft_print_zero(t_options *options, t_argument *arg);
void	ft_putchar(char c, int fd, t_options *options);
void	ft_putnbr(int n, int fd, t_options *options);
void	ft_putstr(char *str, int nb, t_options *options);

/* TOOLS */

int		ft_is_charset(char c, char *set);
int		ft_nbrlen_b_u(unsigned long n, char *base);
int		ft_nbrlen_b(long long n, char *base);
size_t	ft_strlen(const char *str);

#endif