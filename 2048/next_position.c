/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apilate <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:28:03 by apilate           #+#    #+#             */
/*   Updated: 2015/02/28 15:28:04 by apilate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g2048.h"

inline static int	right_position(uint8_t *x)
{
	if (*x < X)
	{
		++(*x);
		return (1);
	}
	return (0);
}

inline static int	left_position(uint8_t *x)
{
	if (*x > 0)
	{
		--(*x);
		return (1);
	}
	return (0);
}

inline static int	up_position(uint8_t *y)
{
	if (*y > 0)
	{
		--(*y);
		return (1);
	}
	return (0);
}

inline static int	down_position(uint8_t *y)
{
	if (*y < X)
	{
		++(*y);
		return (1);
	}
	return (0);
}

int					next_position(uint8_t *x, uint8_t *y,
									enum e_direction direction)
{
	if (direction == UP)
		return (up_position(y));
	else if (direction == DOWN)
		return (down_position(y));
	else if (direction == RIGHT)
		return (right_position(x));
	else if (direction == LEFT)
		return (left_position(x));
	return (-1);
}
