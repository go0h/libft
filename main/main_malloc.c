/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:50:21 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/12 18:26:04 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int n = atoi(argv[1]);
	
	char *arr;
	printf("n = %d\n", n);
	printf("%d = %p\n", n, (void*)arr);
	arr = (char*)malloc(n);
	printf("%d = %p\n", n, (void*)arr);
	return (0);
}
