# Nombre del programa
NAME       = fractol
# Flags de compilacion
FLAGS      = -Wall -Wextra -Werror -g
# Directorios
SRC_DIR    = ./srcs/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/
LIBFT_DIR  = ./libft/
MLX_DIR    = ./MLX42/
# Archivos fuentes y objetos
SRC_FILES  = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES  = $(notdir $(SRC_FILES:.c=.o))
# Direcciones
SRC        = $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR),$(OBJ_FILES))
LIBFT      = $(addprefix $(LIBFT_DIR),libft.a)
MLX        = $(addprefix $(MLX_DIR), libmlx42.a)
# Linkers
LNK        = -Ofast

ifeq ($(shell whoami), panesico)
	BREW = /usr/lib/x86_64-linux-gnu/libglfw.so
else
	BREW = "/Users/$(USER)/.brew/opt/glfw/lib/"
endif
# Se compila el archivo binario (ejecutable).
all: obj $(LIBFT) $(NAME)
# Crea la carpeta donde estará los objetos.
obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $(SRC_DIR)$(notdir $<)
# Compila la biblioteca libft.a
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
# Se compila los objetos con las librerías y archivos
$(NAME): $(OBJ)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compilando, espere unos segundos..."
	@gcc $(OBJ) $(LNK) $(MLX) -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl  -L$(LIBFT_DIR) -lft -lm -o $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generado!"
# Remueve todos los archivos objetos
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "¯\_(ツ)_/¯ Objetos removidos!"
# Remueve todos los archivos objetos, binarios y sus respectivas carpetas
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "(╯°□°）╯︵ ┻━┻ $(NAME) removido!"
# Hace un re-make (como si se hubiera ejecutado Make por primera vez)
re: fclean all
# Le dice al make que estos nombres no son archivos
.PHONY: all clean fclean re