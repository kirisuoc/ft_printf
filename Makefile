CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
LIBFT = ./libft/libft.a
NAME = libftprintf.a

# Colores
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Lista de archivos fuente
SRCS = ft_printf.c aux_functions.c manage_specifiers.c parse_format.c put_functions.c

# Generar lista de archivos objeto (.o) a partir de los .c
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Compilando libft$(RESET)"
	make -C ./libft

# Regla para crear la biblioteca
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)Construyendo $(NAME)$(RESET)"
	@echo "$(GREEN)Creando la biblioteca $(NAME)$(RESET)"
	$(AR) $@ $(OBJS) ./libft/*.o

# Regla para compilar los archivos fuente en objetos
%.o: %.c
	@echo "$(CYAN)Compilando $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas para limpiar los archivos objeto y la biblioteca
clean:
	@echo "$(RED)Limpiando archivos objeto$(RESET)"
	rm -rf $(OBJS)
	make -C ./libft clean

fclean: clean
	@echo "$(RED)Limpiando la biblioteca $(NAME)$(RESET)"
	rm -rf $(NAME)
	make -C ./libft fclean

# Regla para recompilar todo
re: fclean all
	@echo "$(YELLOW)Recompilando todo$(RESET)"

