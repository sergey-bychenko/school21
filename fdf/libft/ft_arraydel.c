/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:16:36 by mwuckert          #+#    #+#             */
/*   Updated: 2019/01/12 16:08:49 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(void **array)
{
	if (array && *array)
		if (*(array + 1))
			ft_arraydel(array + 1);
	if (array)
		ft_memdel(&*array);
}
