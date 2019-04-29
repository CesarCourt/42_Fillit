/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:23 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/06 11:00:49 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		full_tetri(char tetri[], char bufftest[], int fd)
{
	if (fd == 26)
		return (FILE_ERROR);
	if ((tetri[fd] = parsing_first(bufftest)) == 42)
		return (FILE_ERROR);
	return (SUCCESS);
}

int		fillit(char tetri[], t_type *square)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j >= 0)
	{
		if (check_square(square, tetri[j], i) == SUCCESS)
		{
			if (fillit2(square, tetri, &j, &i) == SUCCESS)
				return (SUCCESS);
		}
		else if (square->str[i])
			i++;
		else
		{
			j--;
			if (j >= 0)
				i = remove_square(square, j + 'A', tetri[j]);
		}
	}
	return (ERROR);
}

int		fillit2(t_type *square, char tetri[], int *j, int *i)
{
	full_square(square, tetri[*j], *j + 'A', *i);
	if (tetri[*j + 1] != 42 && check_hole(square, tetri, *j + 1) != SUCCESS)
		*i = remove_square(square, *j + 'A', tetri[*j]);
	else
	{
		*i = i_fillit_the_power(square, tetri, *j + 1);
		*j += 1;
	}
	if (tetri[*j] == 42)
	{
		print_tab(square);
		return (SUCCESS);
	}
	return (CONTINUE);
}
