/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:20:43 by jules             #+#    #+#             */
/*   Updated: 2024/04/21 02:26:18 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3	find_normal(t_objects *obj, t_vec3 hit_pos)
{
	if (!obj)
		return ((t_vec3){1.f, 0.f, 0.f});
	if (obj->obj_type == (t_type)sphere)
		return (sphere_normal(*(t_sphere *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)plane)
		return (plane_normal(*(t_plane *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)cylinder)
		return (cylinder_normal(*(t_cylinder *)obj->obj, hit_pos));
	return ((t_vec3){1.f, 0.f, 0.f});
}

t_vec3	diffuse_light(t_scene scene, t_hitpoint hit)
{
	t_vec3		to_light;

	to_light = normalized(sub(scene->light.pos, hit.hitpos));
	return (scale(hit.obj->color, fmaxf(0.f, dot(to_light, hit.normal_vect))));
}

int	in_light(t_scene scene, t_hitpoint hit)
{
	t_vec3		to_light;
	float		dist_to_light;
	t_ray		ray;
	t_hitpoint	new_hit;

	to_light = sub(scene->light.pos, hit.hitpos);
	dist_to_light = mag(to_light);
	to_light = scale(to_light, 1.f / dist_to_light);
	ray.origin = add(hit.hitpos, scale(hit.normal_vect, EPSILON));
	ray.dir = to_light;
	new_hit = get_hitpoint(scene, ray);
	if ((new_hit.d < 0.f) || (new_hit.d >= dist_to_light))
		return (1);
	return (0);
}
