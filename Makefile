SOURCES =	main.c args.c error.c operations.c instructions.c sort.c \
			stack_sort_1.c stack_sort_2.c stack_sort_3.c
NAME = push_swap
LIBFT = libft/libft.a
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
CC = gcc
FLAGS =  -g

all: ${NAME}

${OBJS_PATH}/%.o: ${SRCS_PATH}/%.c
					mkdir -p ${OBJS_PATH}
					${CC} ${FLAGS} -c $< -o $@ -I libft/include/ -I include/

${NAME}: ${LIBFT} ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}: 
		 make -C libft/ --no-print-directory
clean:
		rm -rf ${OBJS_PATH}

fclean: clean
		rm -rf ${NAME}
	
re: fclean all

norma:
		norminette ${SRCS} include/