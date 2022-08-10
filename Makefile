SOURCES =	main.c args.c error.c operations.c instructions.c sort.c \
			stack_sort_1.c stack_sort_2.c stack_sort_3.c args_2.c
NAME = push_swap
LIBFT = libft/libft.a
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
CC = gcc
FLAGS =  -g
ARG := $(shell shuf -i 1-500)
TESTER = checker_linux

# Colors
GREEN = \33[1;32m
L_CYAN = \33[1;36m
L_BLUE = \33[1;34m
L_GREEN = \33[1;92m
L_PURPLE = \33[1;35m
NC = \033[0m

all: ${NAME}

${OBJS_PATH}/%.o: ${SRCS_PATH}/%.c
					@ mkdir -p ${OBJS_PATH}
					@ echo "Compiling: $<"
					@ ${CC} ${FLAGS} -c $< -o $@ -I libft/include/ -I include/

${NAME}: ${LIBFT} ${OBJS}
			@ ${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}
			@ echo "${GREEN}push_swap successfully compiled!${NC}"

${LIBFT}: 
		@ make -C libft/ --no-print-directory

clean:
		@ rm -rf ${OBJS_PATH}
		@ echo "${L_CYAN}Objects deleted!${NC}"

fclean: clean
		@ make fclean -C libft/ --no-print-directory
		@ rm -rf ${NAME}
		@ echo "${L_BLUE}push_swap deleted!${NC}"
	
re: fclean all

norma:
		norminette ${SRCS} include/

check:	${NAME}
		@echo "${L_PURPLE}Checking ${NAME} with ${TESTER}...${NC}"
		@ ./${NAME} ${ARG} | ./${TESTER} ${ARG}