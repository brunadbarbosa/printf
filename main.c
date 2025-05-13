/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:41:43 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/13 12:17:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	arg = atoi(argv[1]);

		if (arg == 1)
		{
			int idade = 29;
			char *bruna = "Bruna";
			printf("==== Teste 1 ====\n\n");
			printf("String a ser testada:\n");
			printf("Meu nome e %s e tenho %d anos de idade.\n", bruna, idade);
			ft_printf("Meu nome e %s e tenho %d anos de idade.\n", bruna, idade);
		}
		if (arg == 2)
		{
			printf("==== Teste 2 ====\n\n");
			printf("String a ser testada:\n");
			printf("Uma string com tres flags %%% quatro flags %%%%.\n");
			ft_printf("Uma string com tres flags %%% quatro flags %%%%.\n");
		}
		if (arg == 3)
		{
			char	teste[] = "teste";
			char	*pointer = teste;
			printf("==== Teste 3 ====\n\n");
			printf("String a ser testada:\n");
			printf("Uma string com um ponteiro %p.\n", pointer);
			ft_printf("Uma string com um ponteiro %p.\n", pointer);
		}
		if (arg == 4)
		{
			size_t	max = 2147483648;
			printf("==== Teste 4 ====\n\n");
			printf("String a ser testada:\n");
			printf("Uma string com int_max e unsigned %zu.\n", max);
			ft_printf("Uma string com int_max e unsigned %u.\n", max);
		}
		printf("\n==== Fim ====\n");
	}
	else
		printf("Teste com um numero, somente.");
	return (0);
}