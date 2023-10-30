/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:04:59 by seblin            #+#    #+#             */
/*   Updated: 2023/10/30 14:20:21 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_set
{
	char	ph;
	void (*alphanum) (char *s);
} t_set;

int	conditionnal_mapping(char c1, char c2, void (*f) (uintptr_t ptradress), uintptr_t ptradress)
{
	char	set[]
	while (set)
	{
		mystruct.myfunct(arg, 16);
	}
}

int	myfunct()
{
	char *sitoa = ft_itoa_base(va_arg(lst, int), 16, u);
	n_item += ft_strlen(sitoa); 
	ft_putstr_fd(sitoa, 1);
}
	// long int	nl;
	
	// nl = (long int) n;
	// if (nl < 0)
	// {
	// 	nl = -nl;
	// 	ft_putchar_fd("-", 1);
	// }

int	put_nbr_base(unsigned int n, unsigned int base)
{
	int size;
	
	size = 0;
	if (n >= base)
		size +=	put_nbr_base(nl / base);	
	if (nl <= 9)
		ft_putchar_fd(nl % base + 48, 1);
	else
		ft_putchar_fd(nl % base + 55, 1);
	return (size);	
}


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
				
				char *sitoa = ft_itoa_base((va_arg(lst, void *), 16); // uintptr_t
				n_item += 2 + ft_strlen(sitoa);
				ft_putstr_fd("0x", 1); 
				ft_putstr_fd(sitoa, 1);
			}
			else if (*s == 'u') // gerer les overflow
			{
				char *sitoa = ft_itoa_base(va_arg(lst, int), 10); // uintptr_t
				n_item += ft_strlen(sitoa);
				ft_putstr_fd(sitoa, 1);
				
			}
			else if (*s == 'd' || *s == 'i') // gerer les overflow
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
				n_item += ft_strlen(sitoa); // touuper
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


