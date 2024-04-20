/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:14:34 by jules             #+#    #+#             */
/*   Updated: 2024/04/20 16:55:39 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "plane.h"
#include <math.h>

t_plane	create_plane(t_vec3 pos, t_vec3 normal_vector)
{
	t_plane	pl;

	pl.pos = pos;
	pl.normal_vector = normal_vector;
	return (pl);
}

float	plane_intersection(t_ray ray, t_plane pl)
{
	float	denom;
	t_vec3	oc;
	float	t;

	denom = dot(pl.normal_vector, ray.dir);
	if (fabsf(denom) < EPSILON)
		return (-1.f);
	oc = sub(pl.pos, ray.origin);
	t = dot(oc, pl.normal_vector) / denom;
	if (t < 0.f)
		return (-1.f); 
		
	return (t);
}

t_vec3	plane_normal(t_plane pl, t_vec3 hit)
{
	(void) hit;
	return (pl.normal_vector);
}