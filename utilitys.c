/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:12:39 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/01 17:12:50 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memset(void *ptr, char c, int len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)ptr;
	while (i < len)
		str[i++] = c;
}
