/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count_island.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:04 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 19:16:13 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_square5(int i, t_type *square, char nbr)
{
	if (i % square->size == 0)
	{
		if ((square->isl[i + 1] == nbr && (i + 1) % square->size != 0)
			|| square->isl[i - square->size] == nbr)
		{
			square->isl[i] = nbr;
			if (square->str[i + 1] == '.' && (i + 1) % square->size != 0)
				square->isl[i + 1] = nbr;
			if (square->str[i - square->size] == '.')
				square->isl[i - square->size] = nbr;
			return (SUCCESS);
		}
		return (ERROR);
	}
	return (ft_check_square6(i, square, nbr));
}

static int		ft_check_square4(int i, t_type *square, char nbr)
{
	if ((square->isl[i + 1] == nbr && (i + 1) % square->size != 0)
		|| square->isl[i + square->size] == nbr
		|| square->isl[i - 1] == nbr || square->isl[i - square->size] == nbr)
	{
		square->isl[i] = nbr;
		if (square->str[i + 1] == '.' && (i + 1) % square->size != 0)
			square->isl[i + 1] = nbr;
		if (square->str[i + square->size] == '.')
			square->isl[i + square->size] = nbr;
		if (square->str[i - 1] == '.')
			square->isl[i - 1] = nbr;
		if (square->str[i - square->size] == '.')
			square->isl[i - square->size] = nbr;
		return (SUCCESS);
	}
	return (ERROR);
}

static int		ft_check_square3(int i, t_type *square, char nbr)
{
	if (i < square->size * (square->size - 1))
	{
		if (i % square->size == 0)
		{
			if ((square->isl[i + 1] == nbr && (i + 1) % square->size != 0)
				|| square->isl[i + square->size] == nbr
				|| square->isl[i - square->size] == nbr)
			{
				square->isl[i] = nbr;
				if (square->str[i + 1] == '.')
					square->isl[i + 1] = nbr;
				if (square->str[i + square->size] == '.')
					square->isl[i + square->size] = nbr;
				if (square->str[i - square->size] == '.')
					square->isl[i - square->size] = nbr;
				return (SUCCESS);
			}
			return (ERROR);
		}
		else
			return (ft_check_square4(i, square, nbr));
	}
	return (ft_check_square5(i, square, nbr));
}

static int		ft_check_square2(int i, t_type *square, char nbr)
{
	if ((square->isl[i + 1] == nbr && (i + 1) % square->size != 0)
		|| square->isl[i - 1] == nbr
		|| square->isl[i + square->size] == nbr)
	{
		square->isl[i] = nbr;
		if (square->str[i + 1] == '.' && (i + 1) % square->size != 0)
			square->isl[i + 1] = nbr;
		if (square->str[i - 1] == '.')
			square->isl[i - 1] = nbr;
		if (square->str[i + square->size] == '.')
			square->isl[i + square->size] = nbr;
		return (SUCCESS);
	}
	return (ERROR);
}

int				ft_check_square(int i, t_type *square, char nbr)
{
	if (i < square->size)
	{
		if (i == 0)
		{
			if ((square->isl[i + 1] == nbr && (i + 1) % square->size != 0)
				|| square->isl[i + square->size] == nbr)
			{
				square->isl[i] = nbr;
				if (square->str[i + 1] == '.' && (i + 1) % square->size != 0)
					square->isl[i + 1] = nbr;
				if (square->str[i + square->size] == '.')
					square->isl[i + square->size] = nbr;
				return (SUCCESS);
			}
			return (ERROR);
		}
		else
			return (ft_check_square2(i, square, nbr));
	}
	return (ft_check_square3(i, square, nbr));
}
