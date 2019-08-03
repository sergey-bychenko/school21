/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:06:18 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/03 16:53:20 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define W 1300
# define H 1300
# define BUFF_SIZE 111
# define BG_CLR 0xE0FFFF

typedef struct			s_obj
{
	char				type;
	float				xyz[3];
	float				r;
	int					clr;

	struct s_obj		*next;
}						t_obj;

typedef struct			s_rt
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_data;
	t_obj				*obj;
	t_obj				*light;
	int					i;
}						t_rt;

typedef struct			s_ray
{
	float				d[3];
	float				t;
	int					clr;
	t_obj				*obj;
}						t_ray;

int						ft_exit(t_rt *rt);
int						pars_scene(char *str, t_rt *rt);
int						get_next_line(const int fd, char **line);

float					ft_atof(const char *str);
float					ft_scan_digit(char **str);
float					diffuse_reflection(t_rt *rt, t_ray *ray);

t_obj					*new_obj(t_obj **obj);

void					trace_ray(t_rt *rt);
void					dell_all_obj(t_obj **obj);

#endif
