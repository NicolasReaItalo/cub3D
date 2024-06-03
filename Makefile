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
SRCDIR	=	srcs
OBJDIR	=	obj
ifneq ($(LIBFT),false)
	LIB += -I$(LIBFT) -L$(LIBFT) -lft
endif
ifneq ($(MLX),false)
	LIB += -I$(MLX) -L$(MLX) -lmlx_Linux -lbsd -lXext -lX11
endif

GREEN		=	\e[92;118m
YELLOW		=	\e[93;226m
BLUE		=	\e[94;226m
RESET		=	\e[0m
#########################################################
### SOURCES
#########################################################
SRCS	=	data_operations.c\
			events.c\
			exit.c\
			main.c\
			math_utils.c\
			movements.c\
			minimap.c\
			pixel.c\
			rayCast_angles.c\
			rayCast_draw_calculate.c\
			rayCast_draw.c\
			set_imgs.c\
			utils.c\
			win_utils.c\
			scene_parser/map_closing.c\
			scene_parser/map_dimensions.c\
			scene_parser/parse_error_handler.c\
			scene_parser/parse_scene.c\
			scene_parser/parsing_utils.c\
			scene_parser/populate_map.c\
			scene_parser/scene_loader.c\
			scene_parser/set_text_and_col.c

SRC		=	$(addprefix $(SRCDIR)/, $(SRCS))

OBJS	= 	$(SRCS:.c=.o)
OBJ		= 	$(OBJDIR)/main.o $(addprefix $(OBJDIR)/, $(OBJS))	

#########################################################
### REGLES
#########################################################
.PHONY:		all clean fclean re fclean_lib fclean_all bonus

all:		${NAME}

$(NAME): $(OBJ)
ifneq ($(LIBFT),false)
	@echo "$(YELLOW)Making Libft$(RESET)"
	@${MAKE} -C ${LIBFT} -s
	@echo "$(BLUE)Libft ready$(RESET)"
endif
ifneq ($(MLX),false)
	@echo "$(YELLOW)Making MiniLibX$(RESET)"
	@${MAKE} -C ${MLX} -s
	@echo "$(BLUE)MiniLibX ready$(RESET)"
endif
	@echo "$(YELLOW)Compiling$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB) -lm
	@echo "$(GREEN)Ready to use $(_COLOR_BOLD)$@ !$(RESET)"



# Rule to build object files
./$(OBJDIR)/%.o: ./$(SRCDIR)/%.c  
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT) :
	@echo "$(YELLOW)Making $(LIBFT)$(RESET)"
	@make all -sC $(LIBFT_DIR) -s
	@echo "$(BLUE)Ready to use$(RESET)"



fclean_lib:
ifneq ($(LIBFT),false)
	@echo "$(YELLOW)Cleaning Libft$(RESET)"
	@cd $(LIBFT) && make fclean -s
	@echo "$(BLUE)Libft cleaned$(RESET)"
	
endif
ifneq ($(MLX),false)
	@echo "$(YELLOW)Cleanng MiniLibX$(RESET)"
	@cd $(MLX) && make clean -s
	@echo "$(BLUE)MiniLibX cleaned$(RESET)"
	
endif

clean:
	@echo "$(YELLOW)Cleaning objects$(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(BLUE)Objects cleaned$(RESET)"
	

fclean:		clean fclean_lib
	@echo "$(YELLOW)removing $(NAME)$(RESET)"
	@rm -f ${NAME}
	@echo "$(BLUE)$(NAME) removed$(RESET)"
	

fclean_all:	fclean fclean_lib

re:			fclean all
