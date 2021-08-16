/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:52:07 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:07:25 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H
# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 600
# endif
# include <stdint.h>
# include <stdbool.h>
# include "structs/t_window.h"
# include "../libs/libft/includes/ft_lst.h"

typedef struct s_load_line
{
	double		*zs;
	int			nbr;
	int			last_added;
	uint32_t	*colors;
	bool		*color_loaded;
}				t_load_line;

int			args_parser(int argc, char **argv, t_window *win);
void		fdf_parser(int fd, t_window *win);

/*
** Internal parser functions
*/
bool		check_value(char *str, bool point);
int			finish_read(int fd, int code);
int			ft_compare_base(char *str, char *base);
int			check_loaded(t_list *y_list, t_vec2i *mesh_size);
bool		init_list(t_list **list);
void		free_load_line(void	*elem);
void		free_coord_list(t_list **list);
t_face		*error_faces(t_face **faces, int nbr);
int			error_free_coord_list(int code, t_list **coord);
int			error_free(int code, void *ptr);
t_vertex	*list_to_vertices(t_list *y_list, int nbr_vert, t_vec2i	mesh_size);
t_quad		mesh_face_index(t_vec2i size, t_vec2i offset);
t_face		*create_faces(t_vec2i mesh_size, int *obj_nbr);
int			create_mesh(t_list **y_list, t_3dobj **obj);
int			parse_line(char	*line, t_list **y_list);
int			load_coord_col(char *coord, char *color, t_load_line *new_line);
int			load_coord(char *coord, t_load_line *new_line);
int			malloc_new_line(t_load_line **new_line, int nbr);
void		attribute_color(t_vertex *vertices, int nbr);
#endif