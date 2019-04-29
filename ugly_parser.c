/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ugly_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 00:41:23 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/06 00:51:34 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fillit_pars_cmp(char bufftest[], char *tetri, int start
	, int end)
{
	int		i;

	i = start;
	while (i <= end)
	{
		if (tetri[i - start] == bufftest[i])
			i++;
		else if (tetri[i - start] == '.' && bufftest[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

static int		chose_last_piece(char bufftest[], int i, int j)
{
	if (fillit_pars_cmp(bufftest, "###..#", i, j))
		return (6);
	if (fillit_pars_cmp(bufftest, "##....#....#", i, j))
		return (-9);
	if (fillit_pars_cmp(bufftest, "#..###", i, j))
		return (9);
	if (fillit_pars_cmp(bufftest, "##...##", i, j))
		return (0);
	if (fillit_pars_cmp(bufftest, "##..##", i, j))
		return (-5);
	if (fillit_pars_cmp(bufftest, "#....##....#", i, j))
		return (5);
	if (fillit_pars_cmp(bufftest, "###...#", i, j))
		return (3);
	if (fillit_pars_cmp(bufftest, "#....##...#", i, j))
		return (-3);
	if (fillit_pars_cmp(bufftest, "#...###", i, j))
		return (2);
	if (fillit_pars_cmp(bufftest, "#...##....#", i, j))
		return (-2);
	if (fillit_pars_cmp(bufftest, "##....##", i, j))
		return (-4);
	if (fillit_pars_cmp(bufftest, "#...##...#", i, j))
		return (4);
	return (42);
}

static int		chose_good_piece(char bufftest[])
{
	int		i;
	int		j;

	i = 0;
	while (bufftest[i] != '#')
		i++;
	j = 20;
	while (bufftest[j] != '#')
		j--;
	if (j - i == 3)
		return (-1);
	if (fillit_pars_cmp(bufftest, "#....#....#....#", i, j))
		return (1);
	if (fillit_pars_cmp(bufftest, "#....#...##", i, j))
		return (-8);
	if (fillit_pars_cmp(bufftest, "###....#", i, j))
		return (7);
	if (fillit_pars_cmp(bufftest, "##...#....#", i, j))
		return (-7);
	if (fillit_pars_cmp(bufftest, "#....###", i, j))
		return (8);
	if (fillit_pars_cmp(bufftest, "#....#....##", i, j))
		return (-6);
	return (chose_last_piece(bufftest, i, j));
}

int				parsing_first(char bufftest[])
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && bufftest[i] != '\n')
			return (42);
		if (bufftest[i] == '#')
			nbr++;
		else if (i % 5 != 4 && bufftest[i] != '.')
			return (42);
		i++;
	}
	if (nbr != 4)
		return (42);
	return (chose_good_piece(bufftest));
}
