NAME = libft.a

SRC = ft_isalnum.c\
      ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_strlen.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_atoi.c\
	  ft_bzero.c\
	  ft_calloc.c\
	  ft_itoa.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_strchr.c\
	  ft_strdup.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlcpy.c\
	  ft_strncmp.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_substr.c\
	  ft_split.c\
	  ft_putnbr_fd.c\
	  ft_putendl_fd.c\
	  ft_putstr_fd.c\
	  ft_putchar_fd.c\
	  ft_striteri.c\
	  ft_strmapi.c\
	  ft_strtrim.c\
	  ft_memchr.c\

SRC_BONUS = ft_lstadd_front.c\
			ft_lstadd_back.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c\
			ft_lstmap.c\
	  

SRC_FT_PRINTF = ft_printf/ft_print_element.c\
			 ft_printf/ft_printf.c\
			 ft_printf/ft_putaddr_hex.c\
			 ft_printf/ft_putnbr_pf.c\
			 ft_printf/ft_putunbr.c\
			 ft_printf/utils.c\

SRC_GNL = get_next_line/get_next_line.c\
		  get_next_line/get_next_line_utils.c\

OBJ = $(SRC:.c=.o) 

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ_PRINTF = $(SRC_FT_PRINTF:.c=.o)

OBJ_GNL = $(SRC_GNL:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(OBJ_PRINTF) $(OBJ_GNL) libft.h
	ar rcs $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_GNL)

bonus : $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
