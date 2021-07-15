# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 15:10:49 by jberredj          #+#    #+#              #
#    Updated: 2021/07/15 12:12:44 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf.out
CC			=	clang
OPTI		=	#-O3
CFLAGS		=	#-Wall -Wextra -Werror $(OPTI)
DEBUG		=	
HEADERS		=	-I includes/

WIDTH		=	800
HEIGHT		=	600

LIBS		=	libmlx.a libft.a

MLX_UTILS	=	color_utils.c keyboard_hook.c mlx_utils.c mlx_utils2.c window.c

GEOMETRY	=	vec2.c vec3.c line.c projection.c vec3d_rotate.c

3DOBJ		=	3dobj.c put_3dobj.c

MAIN		=	main.c exit.c

SRCS	=	$(MAIN) $(MLX_UTILS) $(GEOMETRY) $(ARWING) $(3DOBJ)
OBJS	=	$(SRCS:.c=.o)

MODULE	=	main mlx_utils geometry 3dobj

$(NAME): $(LIBS) $(MODULE) compile

all: $(NAME)

libmlx.a:
	make -C libs/minilibx-linux/
	cp libs/minilibx-linux/libmlx.a .
	cp libs/minilibx-linux/mlx.h includes/

libft.a:
	make -C libs/libft 
	cp libs/libft/libft.a .

no_opti: OPTI =
no_opti: debug

debug: MODULE += debug_func
debug: DEBUG = -D DEBUG
debug: CFLAGS = -g #-fsanitize=address 
debug: all

mlx_utils: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/mlx_utils/, $(MLX_UTILS)) $(DEBUG)
	mv *.o objs

geometry: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/geometry/, $(GEOMETRY)) $(DEBUG)
	mv *.o objs

3dobj: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/3dobj/, $(3DOBJ)) $(DEBUG)
	mv *.o objs

main: objs
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix srcs/, $(MAIN)) $(DEBUG) -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT)
	mv *.o objs

compile:
	$(CC) $(CFLAGS) $(HEADERS) $(addprefix objs/, $(OBJS)) $(LIBS) -lXext -lX11 -lm -lbsd -o $(NAME) 

objs:
	mkdir -p objs/

clean:
	rm -rf objs
	rm -rf *.o;

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBS)

re: fclean all