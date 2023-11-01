/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:15:15 by seblin            #+#    #+#             */
/*   Updated: 2023/11/01 11:43:27 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("test moi bien pour la :%deme fois\n", 42);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int res;
// ///////////////////////////////
// 	res = ft_printf("NULL %s NULL\n", NULL);
// 	printf("n_item:%d\n", res);
// 	//res = printf("NULL %s NULL\n", NULL);
// 	printf("n_item:%d\n", res);

// 	//("\n");
// 	res = ft_printf("bravo\n");
// 	printf("n_item:%d\n", res);
// 	res = printf("bravo\n");
// 	printf("n_item:%d\n", res);

// 	res = ft_printf("bravo: %s\n", "deu");
// 	printf("n_item:%d\n", res);
// 	res = printf("bravo: %s\n", "deu");
// 	printf("n_item:%d\n", res);

// 	res = ft_printf("b %p j %X c %x b %u j %d c %i c %c e %s 
//t %%\n",&(int) {0}, 175, 175, 42, 42, 42, 'z', "string");
// 	printf("n_item:%d\n", res);
// 	res = ft_printf("b %p j %X c %x b %u j %d c %i c %c e %s t 
//%%\n",&(int) {0}, 175, 175, 42, 42, 42, 'z', "string");
// 	printf("n_item:%d\n", res);
// }