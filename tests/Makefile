#########################################################
### VARIABLES
#########################################################
NAME	=	test_parser
CC		=	cc
HEADERS	=	../headers
CFLAGS	=	-Wall -Wextra -Werror -I ${HEADERS}
#########################################################
### LIBS
#########################################################
LIBFT	=	../libft
MLX		=	../minilibx-linux
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
SRCS	=	../srcs/scene_parser/parse_error_handler.c\
			../srcs/scene_parser/parsing_utils.c\
			../srcs/scene_parser/scene_loader.c\
			../srcs/scene_parser/parse_scene.c\
			../srcs/scene_parser/map_closing.c\
			../srcs/utils.c\
			../srcs/scene_parser/populate_map.c\
			../srcs/scene_parser/set_text_and_col.c\
			../srcs/scene_parser/map_dimensions.c\
			test_parser.c
#########################################################
### DEBUG
#########################################################
DEBUG	=	true
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
.PHONY:		all clean fclean re

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
			# rm -f ${BO_OBJS}

fclean:		clean
			rm -f ${NAME}

fclean_all:	fclean fclean_lib

re:			fclean all
