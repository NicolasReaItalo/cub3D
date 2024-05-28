#########################################################
### VARIABLES
#########################################################
NAME	=	cub3D
CC		=	cc
HEADERS	=	./headers
CFLAGS	=	-Wall -Wextra -Werror -I ${HEADERS}
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
			srcs/events.c\
			srcs/exit.c\
			srcs/main.c\
			srcs/math_utils.c\
			srcs/parsing_utils.c\
			srcs/pixel.c\
			srcs/utils.c\
			srcs/win_utils.c
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
			# rm -f ${BO_OBJS}

fclean:		clean
			rm -f ${NAME}
			# rm -f ${BONUS_N}

fclean_lib:
ifneq ($(LIBFT),false)
			cd $(LIBFT) && make fclean
endif
ifneq ($(MLX),false)
			cd $(MLX) && make clean
endif


fclean_all:	fclean fclean_lib

re:			fclean all
