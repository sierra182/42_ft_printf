/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:04:59 by seblin            #+#    #+#             */
/*   Updated: 2023/10/31 08:05:28 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h> //
#include <stdint.h>

static int	putnbr_base(uintptr_t n, unsigned int base, char casse, char pref)
{
	int	size;

	size = 0;
	if (pref == 'x' && ++size && size++)
		ft_putstr_fd("0x", 1);
	if (n >= base)
		size += putnbr_base(n / base, base, casse, 'z');
	if (n % base <= 9)
		ft_putchar_fd(n % base + 48, 1);
	else if (casse == 'u')
		ft_putchar_fd(n % base + 55, 1);
	else
		ft_putchar_fd(n % base + 87, 1);
	return (++size);
}

static void	manage_placeholder(const char *s, va_list lst, int *n_item, int nbr)
{
	if (*s == '%' && (*n_item)++)
		ft_putchar_fd('%', 1);
	else if (*s == 'c' && (*n_item)++)
		ft_putchar_fd(va_arg(lst, int), 1);
	else if (*s == 's')
	{
		*n_item += ft_strlen(s);
		ft_putstr_fd(va_arg(lst, char *), 1);
	}
	else if ((*s == 'd' || *s == 'i') && (*n_item)++)
	{
		nbr = va_arg(lst, int);
		ft_putnbr_fd(nbr, 1);
		while (nbr > 9 && (*n_item)++)
			nbr /= 10;
	}
	else if (*s == 'u')
		*n_item += putnbr_base(va_arg(lst, unsigned int), 10, 0, 0);
	else if (*s == 'p')
		*n_item += putnbr_base((uintptr_t) va_arg(lst, void *), 16, 'l', 'x');
	else if (*s == 'x')
		*n_item += putnbr_base(va_arg(lst, unsigned int), 16, 'l', 0);
	else if (*s == 'X')
		*n_item += putnbr_base(va_arg(lst, unsigned int), 16, 'u', 0);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		n_item;
	int		nbr;

	nbr = 0;
	n_item = 0;
	va_start(lst, s);
	while (*s)
	{
		if (*s++ == '%')
			manage_placeholder(s, lst, &n_item, nbr);
		else if (++n_item)
			ft_putchar_fd(*(s - 1), 1);
	}
	va_end(lst);
	return (n_item); //valeur neg si pb
}

#include <stdio.h>
int	main(void)
{
	int res;

	res = ft_printf("bravo connard\n%X\n", 175);
	printf("%d\n", res);
}