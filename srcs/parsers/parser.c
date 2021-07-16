/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:36:41 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/16 16:52:01 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "error_code.h"
#include "structs/t_window.h"
#include "../libs/libft/includes/libft.h"
#include "exit.h"
#include "objects.h"
#include "geometry.h"

bool	check_value(char *str, bool point)
{
	if (str == NULL)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		{
			if (point == true && *str == '.')
			{
				str++;
				continue ;
			}
			return (false);
		}
		str++;
	}
	return (true);
}

int	finish_read(int fd, int code)
{
	int		read_line;
	char	*line;

	read_line = 1;
	while (read_line)
	{
		read_line = get_next_line(fd, &line);
		free(line);
		line = NULL;
	}
	
	return (code);
}

void	free_coord_list(t_list **list)
{
	t_list	*elem;

	elem = *list;
	while (!elem->next)
	{
		ft_lstclear((t_list **)&elem->content, free);
		elem = elem->next;
	}
	ft_lstclear(list, free);
}

void	panic_gnl_out(int fd, int code, t_list **list, t_window *win)
{
	finish_read(fd, GNL_ERROR);
	free_coord_list(list);	
	error_exit(code, win);
}

bool	init_list(t_list **list)
{
	*list = ft_lstnew(NULL);
	if (!*list)
		return (false);
	return (true);
}

int	fail_split_free_elem(int code, t_list **elem)
{
	ft_lstclear(elem, free);
	return (code);
}

typedef struct s_load_line
{
	double	*zs;
	int		nbr;
}				t_load_line;


void	fill_double_array(char **coord, double *zs)
{
	int	i;

	i = -1;
	while (coord[++i])
		zs[i] = ft_atof(coord[i]);
}

void	free_load_line(void	*elem)
{
	t_load_line	*elem_cast;

	if (!elem)
		return ;
	elem_cast = (t_load_line *)elem;
	if (elem_cast->zs)
		free(elem_cast->zs);
	free(elem);
}

int	malloc_new_line(t_load_line **new_line, int nbr)
{
	t_load_line	*elem;

	elem = (t_load_line *)malloc(sizeof(t_load_line));
	if (!elem)
		return (MALLOC_ERROR);
	elem->nbr = nbr;
	elem->zs = (double *)malloc(sizeof(double) * elem->nbr);
	if (!elem->zs)
	{
		free(elem);
		return (MALLOC_ERROR);
	}
	*new_line = elem;
	return (0);
}

int	load_line(char **coord, t_list **y_list)
{
	t_load_line	*new_line;
	t_list		*new_elem;
	int			i;

	i = -1;
	while (coord[++i])
		if (!check_value(coord[i], true))
			return (INCORRECT_VALUE);
	if (malloc_new_line(&new_line, ft_split_size(coord)))
		return (MALLOC_ERROR);
	fill_double_array(coord, new_line->zs);
	new_elem = ft_lstnew(new_line);
	if (!new_elem)
	{
		free_load_line(new_line);
		return (MALLOC_ERROR);
	}
	ft_lstadd_back(y_list, new_elem);
	return (0);
}

int	parse_line(char	*line, t_list **y_list)
{
	char	**coord;
	int		error;

	coord = ft_split(line, ' ');
	if (!coord)
		return (MALLOC_ERROR);
	error = load_line(coord, y_list);
	if (error)
		return (error);
	return (0);	
}

int	check_loaded(t_list *y_list, t_vec2i *mesh_size)
{
	t_load_line	content;

	mesh_size->y = ft_lstsize(y_list);
	if (!y_list->content)
			return (MISSING_VALUE);
		content = *(t_load_line *)y_list->content;
	mesh_size->x = content.nbr;
	y_list = y_list->next;
	while (y_list)
	{
		if (!y_list->content)
			return (MISSING_VALUE);
		content = *(t_load_line *)y_list->content;
		if (content.nbr != mesh_size->x)
			return (INCORRECT_VALUE);
		y_list = y_list->next;
	}
	return (0);	
}

uint32_t	get_color_from_z(double z, double z_max)
{
	if (z < (z * z_max) / -8)
		return (0x000133);
	if (z < (z * z_max) / -6)
		return (0x001146);
	if (z < (z * z_max) / -2)
		return (0x00035b);
	if (z < 0)
		return (0x1805db);
	if (z > (z * z_max) / 16)
		return (0xe50000);
	if (z > (z * z_max) / 14)
		return (0x9a0200);
	if (z > (z * z_max) / 12)
		return (0x8f1402);
	if (z > (z * z_max) / 10)
		return (0x922b05);
	if (z > (z * z_max) / 8)
		return (0xb27a01);
	if (z > (z * z_max) / 6)
		return (0xf5bf03);
	if (z > (z * z_max) / 4)
		return (0xfddc5c);
	if (z > (z * z_max) / 2)
		return (0xc8fd3d);
	return (0x56fca2);
}

void	attribute_color(t_vertex *vertices, int nbr)
{
	int	i;
	double	z_max;

	i = -1;
	z_max = 0;
	while (++i < nbr)
		if (vertices[i].coord.z > z_max)
			z_max = vertices[i].coord.z;
	i = -1;
	while (++i < nbr)
		vertices[i].color = get_color_from_z(vertices[i].coord.z, z_max);
}

t_vertex	*list_to_vertices(t_list *y_list, int nbr_vert, t_vec2i	mesh_size)
{
	t_vertex	*vertices;
	t_load_line	elem;
	int			x;
	int			y;

	vertices = (t_vertex *)malloc(sizeof(t_vertex) * nbr_vert);
	if (!vertices)
		return (NULL);
	y = -1;
	while (++y < mesh_size.y)
	{
		x = -1;
		elem = *(t_load_line *)y_list->content;
		while (++x < mesh_size.x)
			vertices[y * mesh_size.x + x].coord = vec3d(x - (mesh_size.x / 2.0), y - (mesh_size.y / 2.0), elem.zs[x]);
		y_list = y_list->next;
	}
	attribute_color(vertices, nbr_vert);
	return (vertices);
}

t_quad	mesh_face_index(t_vec2i size, t_vec2i offset)
{
	return (
		quad(
			(offset.y * size.x) + offset.x,
			(offset.y * size.x) + offset.x + 1,
			((offset.y + 1) * size.x) + offset.x + 1,
			((offset.y + 1) * size.x) + offset.x
		)
	);
}

t_face *create_faces(t_vec2i mesh_size, int *obj_nbr)
{
	int		nbr_faces;
	t_face	*faces;
	t_vec2i	vert_list;

	nbr_faces = (mesh_size.x - 1) * (mesh_size.y - 1);
	faces = (t_face *)malloc(sizeof(t_face) * nbr_faces);
	if (!faces)
		return (NULL);
	*obj_nbr = nbr_faces;
	while (--nbr_faces >= 0)
		faces[nbr_faces].nbr_edges = 4;
	vert_list.y = -1;
	while (++vert_list.y < mesh_size.y - 1)
	{
		vert_list.x = -1;
		while (++vert_list.x < mesh_size.x - 1)
		{
			nbr_faces++;
			faces[nbr_faces].edges = (t_edge *)malloc(sizeof(t_edge) * 4);
			if (!faces[nbr_faces].edges)
				return (NULL);
			set_quad_face(mesh_face_index(mesh_size, vert_list), &faces[nbr_faces]);
		}
	}
	return (faces);
}

int create_mesh(t_list **y_list, t_3dobj **obj)
{
	int		error;
	t_vec2i	mesh_size;
	t_3dobj	*new_mesh;

	error = check_loaded(*y_list, &mesh_size);
	if (error)
		return (INCORRECT_VALUE);
	new_mesh = (t_3dobj *)malloc(sizeof(t_3dobj));
	if (!new_mesh)
		return (MALLOC_ERROR);
	*new_mesh = blank_obj();
	new_mesh->nbr_vertices = mesh_size.x * mesh_size.y;
	new_mesh->vertices = list_to_vertices(*y_list, new_mesh->nbr_vertices, mesh_size);
	if (!new_mesh->nbr_vertices)
	{
		free(new_mesh);
		return (MALLOC_ERROR);
	}
	free_coord_list(y_list);
	new_mesh->faces = create_faces(mesh_size, &new_mesh->nbr_faces);
	if (!new_mesh->faces)
	{
		free_3dobj(new_mesh);
		free(new_mesh);
		return (MALLOC_ERROR);
	}
	new_mesh->orient = vec3d(0.523599, 0.523599, 0.9);
	*obj = new_mesh;
	return (0);
}

void fdf_parser(int fd, t_window *win)
{
	char	*line;
	int		read_line;
	int		error;
	t_list	*y_list;

	y_list = NULL;
	read_line = 1;
	while (read_line == 1)
	{
		read_line = get_next_line(fd, &line);
		if (read_line == -1)
			panic_gnl_out(fd, GNL_ERROR, &y_list, win);
		if (*line != '\0')
			error = parse_line(line, &y_list);
		if (error)
			panic_gnl_out(fd, error, &y_list, win);
		free(line);
	}
	close(fd);
	create_mesh(&y_list, &win->objs);
}
