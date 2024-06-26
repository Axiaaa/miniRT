/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:35:13 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/29 18:28:22 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
Plane:
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
- identifier: pl
- x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
- 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
- R,G,B colors in range [0-255]: 0,0,225
*/
void check_plane(char *s)
{
    char **tmp;
    char **tmp2;
    
    tmp = gc_split(s, ' ');
    if (!tmp)
        exit_error("Error\nMalloc failed in plane.c:29\nExiting...\n");
    tmp2 = gc_split(tmp[1], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in plane.c:32\nExiting...\n");
    while (*tmp2)
        ft_atof(*tmp2++);
    tmp2 = gc_split(tmp[2], ',');
    while (*tmp2)
        if (ft_atof(*tmp2) < -1 || ft_atof(*tmp2++) > 1)
            exit_error("Plane normal vector must be normalized !\nExiting...\n");
    tmp2 = gc_split(tmp[3], ',');
    while (*tmp2)
        if (ft_atof(*tmp2) < 0 || ft_atof(*tmp2++) > 255)
            exit_error("Plane color (RGB) must be between [0,255] !\nExiting...\n");
    printf("✅ Plane OK !\n");
}

void init_plane(char *s, t_minirt *minirt)
{
    char **tmp;
    char **tmp2;
    t_plane *pl;
    t_objects *o;

    (void)minirt;
    tmp = gc_split(s, ' ');
    if (!tmp)
        exit_error("Error\nMalloc failed in plane.c:55\nExiting...\n");
    tmp2 = gc_split(tmp[1], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in plane.c:58\nExiting...\n");
    pl = malloc(sizeof(t_plane));
    pl->pos = (t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])};
    tmp2 = gc_split(tmp[2], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in plane.c:63\nExiting...\n");
    pl->normal_vector = normalized((t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])});
    tmp2 = gc_split(tmp[3], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in plane.c:67\nExiting...\n");
    o = create_obj(plane, pl, (t_vec3){ft_atof(tmp2[0]) / 255, ft_atof(tmp2[1]) / 255, ft_atof(tmp2[2]) / 255});
    minirt->scene->nb_objects++;
    ft_lstadd_back(&minirt->scene->objects, ft_lstnew(o));
}