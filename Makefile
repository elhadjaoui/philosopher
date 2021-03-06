NAME = 			philosopher

CC =			gcc -g

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

SANITIZE = -fsanitize=address

DIR_HEADERS =	./header/

DIR_SRCS =		./src/

	
SRC =			 ft_atoi.c ft_strlen.c ft_itoa.c ft_strdup.c ft_strjoin.c philosopher.c utils.c philo_activities.c
			
SRCS =			$(addprefix $(DIR_SRCS), $(SRC)) 



all:			$(NAME)

$(NAME) :
				@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(SRCS)  -o $(NAME)
				

norme:
				norminette $(SRCS) 
				norminette $(DIR_HEADERS)
# bonus:
# 				@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(SRCS) ./src/bonus/client_bonus.c   -o $(CLIENT)
# 				@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(SRCS) ./src/bonus/server_bonus.c   -o $(NAME)

clean:

fclean:			clean
				@$(RM) $(NAME) $(CLIENT) 
				

re:				fclean all

.PHONY:			all, clean, fclean, re