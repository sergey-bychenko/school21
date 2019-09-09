/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:54:27 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/09 12:24:58 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static float	not_mirror_light(t_ray *ray, t_light *light)
{
	float		intensive_current_light;
	float		l[3];

	if (light->type == 1)
	{
		subtraction_point(light->center, ray->p, l);
	}
	else if (light->type == 2)
	{
		multiplication_point(light->vector, -1.0, l);
	}
		intensive_current_light = light->intensive * dot_product(ray->normal, l) /
		(len_vector(ray->normal) * len_vector(l));
	if (dot_product(ray->normal, l) > 0)
	{
		return (intensive_current_light);
	}
	return (0.0f);
}

static float	mirror_light(t_ray *ray, t_light *light)
{
	float		l[3];
	float		r[3];
	float		d_minus[3];
	float		r_dot_v;
	float		cos_l_n;

	if (light->type == 1)
	{
		subtraction_point(light->center, ray->p, l);
	}
	else if (light->type == 2)
	{
		multiplication_point(light->vector, -1.0, l);
	}
	multiplication_point(ray->d, -1.0, d_minus);
	multiplication_point(ray->normal,
			2.0 * dot_product(ray->normal, l), r);
	subtraction_point(r, l, r);
	if ((r_dot_v = dot_product(d_minus, r)) > 0.0)
	{
		cos_l_n = pow((r_dot_v / (len_vector(r) * len_vector(ray->d))), 50);
		//if (cos_l_n >= 0.85)
		//	ray->clr = ((int)((ray->clr >> 16) * 1.25) << 16)  + ((int)(((ray->clr >> 8) % 256) * 1.25) << 8) + ray->clr % 256 * 1.25;//0xFFFFFF;
		return (light->intensive * cos_l_n);
				//pow((r_dot_v / (len_vector(r) * len_vector(ray->d))), 50));
	}
	return (0.0f);
}

float			diffuse_reflection(t_rt *rt, t_ray *ray)
{
	float		intensive_light;
	t_light		*light;
	t_obj		*curr_light;

	intensive_light = 0.0;
	curr_light = rt->light;
	while (curr_light)
	{
		light = curr_light->shape;
		if (light->type == 0 && light->intensive > 0.0)
			intensive_light += light->intensive;
		else if (light->type != 0 && check_shadow(rt, ray, light) == SUCCESS)
		{
			intensive_light += not_mirror_light(ray, light);
			intensive_light += mirror_light(ray, light);
		}
		curr_light = curr_light->next;
	}
	return (intensive_light);
}

				// if (ray->d[0] == 0.0 && ray->d[1] == 0.0)
				// {
				// 	printf("\n\nx %f y %f z %f\n", l[0], l[1], l[2]);
				// 	printf("x %f y %f z %f\n", ray->normal[0], ray->normal[1], ray->normal[2]);
				// 	printf("%f\n", dot_product(ray->normal, l)/(len_vector(ray->normal) * len_vector(l)));
				// } //принты векторов в центре экрана
