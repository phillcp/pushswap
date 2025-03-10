# Name of the program built
NAME_CHECKER		:=		checker
NAME_PUSH_SWAP		:=		push_swap

# Name directory
PATH_SRC			:=		src
PATH_CHECKER		:=		$(PATH_SRC)/checker
PATH_PUSH_SWAP		:=		$(PATH_SRC)/push_swap
PATH_UTILS			:=		$(PATH_SRC)/utils
PATH_BUILD			:=		build
PATH_LIBFT			:=		libft

# List of sources
SRCS_CHECKER		:=		$(shell find $(PATH_CHECKER) -name *.c)
OBJS_CHECKER		:=		$(SRCS_CHECKER:%.c=$(PATH_BUILD)/%.o)
SRCS_PUSH_SWAP		:=		$(shell find $(PATH_PUSH_SWAP) -name *.c)
OBJS_PUSH_SWAP		:=		$(SRCS_PUSH_SWAP:%.c=$(PATH_BUILD)/%.o)
SRCS_UTILS			:=		$(shell find $(PATH_UTILS) -name *.c)
OBJS_UTILS			:=		$(SRCS_UTILS:%.c=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC					:=		cc

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror #-Wpedantic -Werror=pedantic -pedantic-errors -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Wuninitialized -Winit-self -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wstrict-overflow=5 -Wundef -fdiagnostics-show-option -fstack-protector-all -fstack-clash-protection -Wformat-signedness -Wformat-truncation=2 -Wformat-overflow=2 -Wlogical-op -Wstringop-overflow=4 -g -fsanitize=address -fsanitize-recover=address -fno-omit-frame-pointer -fno-common -fsanitize=pointer-subtract -fsanitize=pointer-compare -fsanitize=undefined -fsanitize=leak
FLAG_INC			:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAG_OPTIMIZATION	:=		-O3
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG) $(FLAG_OPTIMIZATION)

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Flags - linking
FLAG_LIBFT			:=		-L$(PATH_LIBFT) -lft 

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]

# General functions
all:						init $(NAME_CHECKER) $(NAME_PUSH_SWAP)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(NAME_CHECKER) and $(NAME_PUSH_SWAP)\n"
							@ make -C $(PATH_LIBFT)

$(NAME_CHECKER):			$(OBJS_CHECKER) $(OBJS_UTILS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS_CHECKER) $(OBJS_UTILS) $(FLAG_LIBFT)

$(NAME_PUSH_SWAP):			$(OBJS_PUSH_SWAP) $(OBJS_UTILS)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS_PUSH_SWAP) $(OBJS_UTILS) $(FLAG_LIBFT)

$(PATH_BUILD)/%.o:	%.c
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ make -C $(PATH_LIBFT) clean
							@ printf "$(_INFO) Deleted files and directory\n"

fclean:						clean
							@ $(RM) $(NAME_CHECKER) $(NAME_PUSH_SWAP)
							@ make -C $(PATH_LIBFT) fclean

re:							fclean all

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

# Format functions

normH:
							@ norminette $(shell find $(PATH_SRC) -name *.h)
							@ make -C $(PATH_LIBFT) normH

normC:
							@ norminette $(shell find $(PATH_SRC) -name *.c)
							@ make -C $(PATH_LIBFT) normC

norm:						normH normC

.PHONY:						all clean fclean re

-include $(DEPS)
