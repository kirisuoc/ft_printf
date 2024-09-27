CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

# Colores
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Lista de archivos fuente
BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcmp.c ft_memcpy.c ft_memchr.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c

# SRCS = $(shell ls *.c) --> Otra forma


# Generar lista de archivos objeto (.o) a partir de los .c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Regla principal
all: $(NAME)

# Regla para crear la biblioteca
$(NAME): $(OBJS)
	@echo "$(GREEN)Construyendo $(NAME)$(RESET)"
	@echo "$(GREEN)Creando la biblioteca $(NAME)$(RESET)"
	ar rcs $@ $^

# Regla para compilar los archivos fuente en objetos
%.o: %.c
	@echo "$(CYAN)Compilando $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas para limpiar los archivos objeto y la biblioteca
clean:
	@echo "$(RED)Limpiando archivos objeto$(RESET)"
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$(RED)Limpiando la biblioteca $(NAME)$(RESET)"
	rm -rf $(NAME)

# Regla para recompilar todo
re: fclean all
	@echo "$(YELLOW)Recompilando todo$(RESET)"

# Regla bonus
bonus: $(BONUS_OBJS)
	@echo "$(GREEN)Añadiendo archivos bonus a la biblioteca $(NAME)$(RESET)"
	ar rcs $(NAME) $(BONUS_OBJS)
