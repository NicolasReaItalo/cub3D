#########################################################
### VARIABLES
#########################################################
NAME	=	cub3D
CC		=	cc
HEADERS	=	./headers
CFLAGS	=	-Wall -Wextra -Werror -g3 -I ${HEADERS}
#########################################################
### LIBS
#########################################################
LIBFT	=	libft
MLX		=	minilibx-linux
ifneq ($(LIBFT),false)
	LIB += -I$(LIBFT) -L$(LIBFT) -lft
endif
ifneq ($(MLX),false)
	LIB += -I$(MLX) -L$(MLX) -lmlx_Linux -lbsd -lXext -lX11
endif
#########################################################
### SOURCES
#########################################################
OBJS	=	${SRCS:.c=.o}
SRCS	=	srcs/colors.c\
			srcs/data_operations.c\
			srcs/events.c\
			srcs/exit.c\
			srcs/main.c\
			srcs/math_utils.c\
			srcs/movements.c\
			srcs/pixel.c\
			srcs/rayCast_angles.c\
			srcs/rayCast_draw_calculate.c\
			srcs/rayCast_draw.c\
			srcs/utils.c\
			srcs/set_imgs.c\
			srcs/win_utils.c\
			srcs/scene_parser/map_closing.c\
			srcs/scene_parser/map_dimensions.c\
			srcs/scene_parser/parse_error_handler.c\
			srcs/scene_parser/parse_scene.c\
			srcs/scene_parser/parsing_utils.c\
			srcs/scene_parser/populate_map.c\
			srcs/scene_parser/scene_loader.c\
			srcs/scene_parser/set_text_and_col.c
#########################################################
### DEBUG
#########################################################
DEBUG	=	false
SANITIZE =	false
ifeq ($(DEBUG),true)
	CFLAGS += -g3
endif
ifeq ($(SANITIZE),true)
	CFLAGS += -fsanitize=address
endif
#########################################################
### REGLES
#########################################################
.PHONY:		all clean fclean re fclean_lib fclean_all bonus

all:		${NAME}

${NAME}:	${OBJS}
ifneq ($(LIBFT),false)
			${MAKE} -C ${LIBFT}
endif
ifneq ($(MLX),false)
			${MAKE} -C ${MLX}
endif
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} -lm
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

fclean_lib:
ifneq ($(LIBFT),false)
			cd $(LIBFT) && make fclean
endif
ifneq ($(MLX),false)
			cd $(MLX) && make clean
endif


fclean_all:	fclean fclean_lib

re:			fclean all
