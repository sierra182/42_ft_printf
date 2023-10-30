/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:04:59 by seblin            #+#    #+#             */
/*   Updated: 2023/10/29 19:23:43 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		n_item;
	
	n_item = 0;
	va_start(lst, s);
	while (*s)
	{
		if (*s == '%')
		{	
			s++;		
			if (*++s == '%')
			{
				n_item++;
				ft_putchar_fd('%', 1); // ajouter ft_putchar
			}
			else if (*s == 'c')
			{
				n_item++;
				ft_putchar_fd(va_arg(lst, char), 1);
			}
			else if (*s == 's')
			{
				n_item += ft_strlen(s);
				ft_putstr_fd(va_arg(lst, char *), 1);
			}
			else if (*s == 'p')
			{
				ft_putstr_fd("0x", 1);
				char *sitoa = ft_itoa_base(va_arg(lst, void *), 16);
				n_item += 2 + ft_strlen(sitoa);
				ft_putstr_fd(sitoa, 1);
			}
			else if (*s == 'd' || *s == 'i' || *s == 'u')
			{
				char *sitoa = ft_itoa_base(va_arg(lst, int), 10);
				n_item += ft_strlen(sitoa);
				ft_putstr_fd(sitoa, 1);
				
			}
			else if (*s == 'x')
			{
				char *sitoa = ft_itoa_base(va_arg(lst, int), 16, l);
				n_item += ft_strlen(sitoa);
				ft_putstr_fd(sitoa, 1);				
			}
			else if (*s == 'X')
			{
				char *sitoa = ft_itoa_base(va_arg(lst, int), 16, u);
				n_item += ft_strlen(sitoa);
				ft_putstr_fd(sitoa, 1);				
			}
		}
		else
			ft_putchar_fd(*s, 1);
		s++;
	}
	va_end(lst);
	return (n_item);
}


