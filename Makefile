NAME =	philo

FLAGS =	-Wall -Werror -Wextra

SRCS =	$(shell find . -name '*.c')
FILES =	$(shell find . -name '*.c' -name '*.h')

OBJ =	$(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ)
	@$(CC) $(SRCS) -o $(NAME) -lpthread
	@echo "\nDone!"
	@$(MAKE) clean

all : $(NAME)

norm:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
