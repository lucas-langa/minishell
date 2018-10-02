NAME = minishell
SRCS = read.c display_utilities.c arr_utils.c manipulate_env.c builtin_cmd.c\
		utility_funcs.c 
LFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
SIGINT
$(NAME) : $(SRCS) 
	cc $(SRCS) $(LFT) $(FLAGS) -o minishell

clean: make -C libft/ clean
	rm minishell

#fclean: clean
	#make -C libft/ fclean

re: 
	make -C libft/ re
	fclean all

$(LFT):
	make -C libft/
