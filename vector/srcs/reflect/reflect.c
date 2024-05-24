/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:43:10 by jules             #+#    #+#             */
/*   Updated: 2024/05/04 11:48:29 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	reflect(t_vec3 u, t_vec3 n)
{
	float	d;

	d = dot(u, n);
	return (add(u, scale(n, -2.f * d)));
}