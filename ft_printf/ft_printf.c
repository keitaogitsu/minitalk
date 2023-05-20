/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:51:04 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/27 13:16:47 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_proc_per(const char **fmt, int *n, va_list *ap)
{
	(*fmt)++;
	if (**fmt == 'c')
		ft_print_c(fmt, n, ap);
	else if (**fmt == 's')
		ft_print_s(fmt, n, ap);
	else if (**fmt == 'd' || **fmt == 'i')
		ft_print_int(fmt, n, ap);
	else if (**fmt == 'u')
		ft_print_unint(fmt, n, ap);
	else if (**fmt == 'x' || **fmt == 'X')
		ft_print_hexa(fmt, n, ap);
	else if (**fmt == 'p')
		ft_print_pointer(fmt, n, ap);
	else if (**fmt == '%')
		ft_print_per(fmt, n);
}

static void	ft_print_str(const char **start, const char **fmt, int *n)
{
	int	putsize;

	while (**fmt != '%' && **fmt)
		(*fmt)++;
	putsize = write(1, *start, *fmt - *start);
	if (putsize == -1)
		*n = -1;
	else
		*n += putsize;
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			ft_print_str(&start, &fmt, &n);
		else
			ft_proc_per(&fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}

// #include <stdio.h>

// void	ft_printf(const char *fmt, ...)
// {
// 	va_list ap;

// 	va_start(ap, fmt);

// 	// char c = (char)va_arg(ap, int);
// 	printf("arg_2: %i\n", va_arg(ap, int));
// 	printf("arg_3: %f\n", va_arg(ap, double));
// 	va_end(ap);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	// char *arg_1 = "aaaa";
// 	// int arg_2 = 5;
// 	// double arg_3 = 3.14;
// 	int	a;

// 	// ft_printf(arg_1, arg_2, arg_3);
// 	// ft_printf("abcd%cfg%slmn\n", 'e', "hijk");
// 	// ft_printf("ab%dcde%ufg\n", INT_MIN, UINT_MAX);
// 	a = printf("%x||%X\n", 88888831, 88888831);
// 	ft_printf("%d%%%i\n", a, 1234);
// 	printf("本家:%p\n", &a);
// 	ft_printf("ft_printf:%p\n", &a);
// }
