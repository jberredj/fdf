# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 15:10:49 by jberredj          #+#    #+#              #
#    Updated: 2021/09/20 17:00:09 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
CC				=	clang
OPTI			=	-O2
CFLAGS			=	-Wall -Werror -Wextra $(OPTI)

SRC_DIR			= 	srcs
INC_DIR			=	includes
OBJ_DIR			=	objs

WIDTH			=	1280
HEIGHT			=	720

LIBS			=	libmlx.a libft.a

###############################################################################
##								Source files								 ##
###############################################################################
3DOBJ			=	3dobj.c edges.c faces.c put_3dobj.c quad.c tri.c

GEOMETRY		=	line.c projection.c vec2.c vec3.c vec3d_rotate.c

MLX_UTILS		=	argb.c color_utils.c keypressed_hook.c \
					keyreleased_hook.c mlx_utils.c mlx_utils2.c window.c

PARSERS			=	args_parser.c color_loader.c coord_loaders.c \
					create_3dobj.c fdf_parser_error.c fdf_parser_utils.c \
					fdf_parser.c line_loader.c list_to_vertices.c \
					malloc_new_line.c 

MAIN			=	main.c exit.c render_loop.c

SRCS			=	$(addprefix srcs/, $(MAIN)) \
					$(addprefix srcs/mlx_utils/, $(MLX_UTILS)) \
					$(addprefix srcs/geometry/, $(GEOMETRY)) \
					$(addprefix srcs/3dobj/, $(3DOBJ)) \
					$(addprefix srcs/parsers/, $(PARSERS))

STRUCTS			=	t_3dobj.h t_argb.h t_img.h t_point.h t_vec.h t_window.h
HEADERS			=	$(addprefix structs/, $(STRUCTS)) \
					color_utils.h error_code.h exit.h geometry.h mlx_utils.h \
					mlx.h objects.h \
					parsers.h qwerty.h render_loop.h window.h

OBJS			=	$(addprefix objs/, $(notdir $(SRCS:.c=.o)))

###############################################################################
##							Color output char								 ##
###############################################################################
BLUE			=\033[0;34m
NC				=\033[0m
LIGHT_PURPLE	=\033[1;35m
GREEN			=\033[0;32m
RED				=\033[0;31m

###############################################################################
## 							Mandatory recipes								 ##
###############################################################################

all: $(NAME)

$(NAME): $(LIBS) $(OBJ_DIR) $(OBJS)
	printf "$(BLUE)Linking $(LIGHT_PURPLE)$(NAME) $(BLUE)executable$(NC)\n"
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) $(LIBS) \
		-lXext -lX11 -lm -lbsd -o $(NAME)
	printf "$(GREEN)Completed$(NC)\n"

clean:
	printf "$(RED)Removing objects files$(NC)\n"
	rm -rf objs
	rm -rf *.o;

fclean: clean
	printf "$(RED)Removing $(LIGHT_PURPLE)$(NAME) \
	$(RED)executable\nRemoving libraries$(NC)\n"	
	rm -rf $(NAME)
	rm -rf $(LIBS)

re: fclean all

###############################################################################
## 								Extra recipes								 ##
###############################################################################

ffclean: fclean
	make -C libs/libft fclean
	make -C libs/minilibx-linux clean

$(OBJS): $(SRCS)
	printf "$(BLUE)Compiling $(LIGHT_PURPLE)$(NAME) $(BLUE)sources$(NC)\n"
	find ./objs/ -type f -exec touch {} +
	$(foreach source,$?, \
	$(CC) -I $(INC_DIR) $(CFLAGS) -c $(source);printf "Compiling $(LIGHT_PURPLE) \
	$(notdir $(source) $(NC)\n");)
	mv -f $(notdir $(?:.c=.o)) objs/

$(SRCS): $(addprefix $(INC_DIR)/, $(HEADERS))

libmlx.a:
	make -C libs/minilibx-linux/
	cp libs/minilibx-linux/libmlx.a .
	cp libs/minilibx-linux/mlx.h includes/

libft.a:
	make -C libs/libft 
	cp libs/libft/libft.a .

no_opti: OPTI =
no_opti: debug

debug: CFLAGS = -g 
debug: all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.SILENT:

###############################################################################
## 								Norm recipe									 ##
###############################################################################

norm:
	printf "$(BLUE)Checking norm$(NC)\n"
#		   Removing mlx.h, because it's not normed and cause norminette to fail
#												↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	norminette $(SRCS) $(addprefix $(INC_DIR)/, $(filter-out mlx.h, $(HEADERS))) \
	libs/libft ; if [ "$$?" -ne "0" ]; then printf "$(RED)NORM ERROR$(NC)\n"; \
	else printf "$(GREEN)NORM OK$(NC)\n";fi