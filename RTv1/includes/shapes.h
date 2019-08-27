/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:55:21 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/27 18:04:36 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# define PLANE 11
# define SPHERE 12
# define CYLINDER 13
# define CONE 14

typedef struct			s_plane
{
	float				plane_dot[3];
	float				plane_normal[3];
}						t_plane;

typedef struct			s_sphere
{
	float				sphere_center[3];
	float				sphere_radius;
}						t_sphere;

typedef struct			s_cylinder
{
	float				cylinder_start[3];
	float				cylinder_axis[3];
	float				cylinder_radius;
}						t_cylinder;

typedef struct			s_cone
{
	float				cone_vertex[3];
	float				cone_axis[3];
	float				cone_angle_tangent;
}						t_cone;

#endif