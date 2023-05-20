/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:58:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/26 16:28:10 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <inttypes.h>

void	ft_print_c(const char **fmt, int *n, va_list *ap);
void	ft_print_s(const char **fmt, int *n, va_list *ap);
size_t	ft_strlen(const char *s);
void	ft_print_int(const char **fmt, int *n, va_list *ap);
ssize_t	ft_putchar(char c);
void	ft_print_unint(const char **fmt, int *n, va_list *ap);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_print_hexa(const char **fmt, int *n, va_list *ap);
void	ft_print_pointer(const char **fmt, int *n, va_list *ap);
ssize_t	ft_putstr(char *s);
void	ft_print_per(const char **fmt, int *n);
int		ft_printf(const char *fmt, ...);

#endif