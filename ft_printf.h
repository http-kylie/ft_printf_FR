/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:45:00 by kytan             #+#    #+#             */
/*   Updated: 2024/03/15 07:45:00 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
	# define NIL "(nil)"
#elif defined(__linux__)
	# define NIL "(nil)"
#elif defined(__APPLE__) && defined(__MACH__)
	# define NIL "0x0"
#endif

int		ft_putchar(unsigned int c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);

int		ft_putptr(void *n);

int		ft_putdec(long n);
int		ft_putunint(unsigned n);
int		ft_puthex(unsigned long int n, char specifier);

int		ft_formats(char c, va_list inputs);
int		ft_printf(const char *s, ...);

#endif