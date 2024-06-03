#########################################################
### VARIABLES
#########################################################
NAME		= libft.a
CC			= cc
AR			= ar
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= -rcs
#########################################################
### SOURCES
#########################################################
OBJS	=	${SRCS:.c=.o}
SRCS	=	ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_printf.c\
			ft_put_char.c\
			ft_put_str.c\
			ft_put_int.c\
			ft_put_uint.c\
			ft_put_hex.c\
			ft_put_ptr.c\
			ft_lstadd_back.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstsize.c\
			ft_lstadd_front.c\
			ft_lstdelone.c\
			ft_lstlast.c\
			ft_lstnew.c\
			get_next_line.c\
			get_next_line_utils.c
INCLDS	=	.
#########################################################
### REGLES
#########################################################
.PHONY:		all clean fclean re

all:		${NAME}

.o:.c
			${CC} ${CFLAGS} -I ${INCLDS} -c $< -o $@

${NAME}:	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}

fclean:		clean
	@rm -f ${NAME}

re:			fclean all
