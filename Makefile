NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -g3 

LDFLAGS = -lpthread

SRC = 	./src/main.c \
		./src/manage.c \
		./src/philos.c \
		./src/rest.c \
		./src/theorize.c \
		./src/devour.c \
		./src/create_routine.c \
		./src/utils.c \
		./src/validate.c \

OBJ_DIR = obj

OBJ = $(SRC:./src/%.c=$(OBJ_DIR)/%.o)

HEADERS	= -I ./include 

OK_COLOR    = \033[0;32m

all: intro $(NAME)

intro:
	@printf "%b" "$(OK_COLOR)"

	@echo "   "
	@echo "███████╗ █████╗ ████████╗    ███████╗██╗     ███████╗███████╗██████╗     ████████╗██╗  ██╗██╗███╗   ██╗██╗  ██╗    ██████╗ ███████╗██████╗ ███████╗ █████╗ ████████╗"
	@echo "██╔════╝██╔══██╗╚══██╔══╝    ██╔════╝██║     ██╔════╝██╔════╝██╔══██╗    ╚══██╔══╝██║  ██║██║████╗  ██║██║ ██╔╝    ██╔══██╗██╔════╝██╔══██╗██╔════╝██╔══██╗╚══██╔══╝"
	@echo "█████╗  ███████║   ██║       ███████╗██║     █████╗  █████╗  ██████╔╝       ██║   ███████║██║██╔██╗ ██║█████╔╝     ██████╔╝█████╗  ██████╔╝█████╗  ███████║   ██║   "
	@echo "██╔══╝  ██╔══██║   ██║       ╚════██║██║     ██╔══╝  ██╔══╝  ██╔═══╝        ██║   ██╔══██║██║██║╚██╗██║██╔═██╗     ██╔══██╗██╔══╝  ██╔═══╝ ██╔══╝  ██╔══██║   ██║   "
	@echo "███████╗██║  ██║   ██║       ███████║███████╗███████╗███████╗██║            ██║   ██║  ██║██║██║ ╚████║██║  ██╗    ██║  ██║███████╗██║     ███████╗██║  ██║   ██║   "
	@echo "╚══════╝╚═╝  ╚═╝   ╚═╝       ╚══════╝╚══════╝╚══════╝╚══════╝╚═╝            ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝    ╚═╝  ╚═╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   "
                                                                                                                                                                    


$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@ -g3 $(HEADERS)
	
$(NAME): $(OBJ)
	@$(CC) -g3 $(OBJ) $(HEADERS) -o $(NAME) $(LDFLAGS) 
#-fsanitize=address
	@echo "Compilation complete!"

clean:
	@rm -rf $(OBJ_DIR) 

fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaning completed!"

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -q --track-origins=yes ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
