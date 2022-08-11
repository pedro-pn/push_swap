SOURCES =	main.c args.c error.c operations.c instructions.c sort.c \
			stack_sort_1.c stack_sort_2.c stack_sort_3.c args_2.c
BSOURCES =	main.c args.c args_2.c error.c instructions.c operations.c \
			operations_2.c
NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a
SRCS_PATH = srcs
OBJS_PATH = objs
BSRCS_PATH = srcs_bonus
BOBJS_PATH = objs_bonus
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
BOBJS = ${addprefix ${BOBJS_PATH}/, ${BSOURCES:.c=.o}}
CC = gcc
FLAGS =  -Werror -Wextra -Wall
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

bonus: ${BONUS}

${OBJS_PATH}/%.o: ${SRCS_PATH}/%.c
					@ mkdir -p ${OBJS_PATH}
					@ echo "Compiling: $<"
					@ ${CC} ${FLAGS} -c $< -o $@ -I libft/include/ -I include/

${BOBJS_PATH}/%.o: ${BSRCS_PATH}/%.c
					@ mkdir -p ${BOBJS_PATH}
					@ echo "Compiling: $<"
					@ ${CC} ${FLAGS} -c $< -o $@ -I libft/include/ -I include/

${NAME}: ${LIBFT} ${OBJS}
			@ ${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}
			@ echo "${GREEN}${NAME} successfully compiled!${NC}"

${BONUS}: ${LIBFT} ${BOBJS}
			@ ${CC} ${FLAGS} ${BOBJS} ${LIBFT} -o ${BONUS}
			@ echo "${L_PURPLE}${BONUS} successfully compiled!${NC}"

${LIBFT}: 
		@ make -C libft/ --no-print-directory

clean:
		@ rm -rf ${OBJS_PATH} ${BOBJS_PATH}
		@ echo "${L_CYAN}Objects deleted!${NC}"

fclean: clean
		@ make fclean -C libft/ --no-print-directory
		@ rm -rf ${NAME} ${BONUS}
		@ echo "${L_BLUE}push_swap deleted!${NC}"
	
re: fclean all

norma:
		norminette ${SRCS} include/ $(BSRCS_PATH)

check:	${NAME}
		@echo "${L_PURPLE}Checking ${NAME} with ${TESTER}...${NC}"
		@ ./${NAME} ${ARG} | ./${TESTER} ${ARG}