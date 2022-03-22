# === LIBFT ===

NAME				:=		libft.a
CC					:=		gcc
CFLAGS				:=		-Wall -Wextra -Werror
INCLUDE				:=		-I includes



# --- FT_CTYPE ---
FT_CTYPE_DIR		:=		./srcs/ft_ctype
FT_CTYPE_FILES		:=		$(addprefix $(FT_CTYPE_DIR)/, \
							ft_isalnum.c \
							ft_isalpha.c \
							ft_isascii.c \
							ft_isdigit.c \
							ft_isprint.c \
							ft_tolower.c \
							ft_toupper.c \
							ft_str_isinteger.c \
							ft_str_isdecimal.c \
)

# --- FT_STDIO ---
FT_STDIO_DIR		:=		./srcs/ft_stdio
FT_STDIO_FILES		:=		$(addprefix $(FT_STDIO_DIR)/, \
							ft_putchar_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c \
							ft_putstr_fd.c \
)

# --- FT_STDLIB ---
FT_STDLIB_DIR		:=		./srcs/ft_stdlib
FT_STDLIB_FILES		:=		$(addprefix $(FT_STDLIB_DIR)/, \
							ft_abs.c \
							ft_atoi.c \
							ft_calloc.c \
							ft_free_with_set.c \
							ft_free_dptr.c \
							ft_free_ptr.c \
							ft_itoa.c \
							ft_swap_ptr.c \
)

# --- FT_STRINGS ---
FT_STRINGS_DIR		:=		./srcs/ft_strings
FT_STRINGS_FILES	:=		$(addprefix $(FT_STRINGS_DIR)/, \
							ft_bzero.c \
							ft_memccpy.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_memset.c \
							ft_split.c \
							ft_strchr.c \
							ft_strdup.c \
							ft_strndup.c \
							ft_safe_strdup.c \
							ft_strjoin.c \
							ft_safe_strjoin.c \
							ft_strjoin_free.c \
							ft_strlcat.c \
							ft_strlcpy.c \
							ft_strlen.c \
							ft_strindexlen.c \
							ft_strnlen.c \
							ft_strmapi.c \
							ft_streq.c \
							ft_strcmp.c \
							ft_strneq.c \
							ft_strncmp.c \
							ft_strnstr.c \
							ft_strrchr.c \
							ft_strtrim.c \
							ft_substr.c \
							ft_strpbrk.c \
							ft_strpbrk_len.c \
							ft_strspace_len.c \
							ft_dstrsize.c \
)

# --- FT_LIST ---
FT_LIST_DIR			:=		./srcs/ft_list
FT_LIST_FILES		:=		$(addprefix $(FT_LIST_DIR)/, \
							ft_lstadd_back.c \
							ft_lstadd_front.c \
							ft_lstclear.c \
							ft_lstdelone.c \
							ft_lstiter.c \
							ft_lstlast.c \
							ft_lstnew.c \
							ft_lstsize.c \
							ft_lst_to_dptr.c \
)

# --- FT_DLST ---
FT_DLST_DIR			:=		./srcs/ft_dlst
FT_DLST_FILES		:=		$(addprefix $(FT_DLST_DIR)/, \
							ft_dlst_eject.c \
							ft_dlst_insert.c \
							ft_dlst_link.c \
							ft_dlstconnect.c \
							ft_dlstadd_back.c \
							ft_dlstadd_front.c \
							ft_dlstinit.c \
							ft_dlstnew.c \
							ft_dlstsize.c \
							ft_dlstdelone.c \
							ft_dlstclear.c \
							ft_dlstiter.c \
							ft_dlst_to_dptr.c \
)



# --- SRCS & OBJS ---
SRCS_FILES			:=		$(FT_CTYPE_FILES) \
							$(FT_STDIO_FILES) \
							$(FT_STDLIB_FILES) \
							$(FT_STRINGS_FILES) \
							$(FT_LIST_FILES) \
							$(FT_DLST_FILES)

OBJS_DIR			:=		./_objs

OBJS_FILES			:=		$(addprefix $(OBJS_DIR)/, $(notdir $(SRCS_FILES:.c=.o)))

# --- VPATH ---
VPATH				:=		$(FT_CTYPE_DIR) \
							$(FT_STDIO_DIR) \
							$(FT_STDLIB_DIR) \
							$(FT_STRINGS_DIR) \
							$(FT_LIST_DIR) \
							$(FT_DLST_DIR)



# --- COLOR ---
RESET				:=		\033[0m
RED					:=		\033[0;31m
GREEN				:=		\033[0;32m
YELLOW				:=		\033[0;33m
BLUE				:=		\033[0;34m
CYAAN				:=		\033[0;36m
WHITE				:=		\033[0;37m

# --- PERCENTAGE ---
T					=		$(words $(OBJS_FILES))
N					=		0
C					=		$(words $N)${eval N+= 1}
PERCENTAGE			=		"`expr $C '*' 100 / $T`%"
MESSAGE				=		"%-100b\r" "$(YELLOW)Compiling $(NAME) ... $(PERCENTAGE)$(RESET)"



# --- COMPILE ---
$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	@printf $(MESSAGE)

# --- MAKE ---
$(NAME): $(OBJS_FILES)
	@ar rcs $(NAME) $(OBJS_FILES)
	@printf "\n$(GREEN)CREATED $(NAME)$(RESET)\n"

all: $(NAME)

clean:
	@rm -f $(OBJS_FILES)
	@echo "$(RED)CLEAN  : rm -f $(NAME) objs$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FCLEAN : rm -f $(NAME)$(RESET)"

re: fclean all

d: CFLAGS += -D SANITIZER=1 -g3 -fsanitize=address -fsanitize=integer -fsanitize=undefined
d: re

ck: CFLAGS += --analyze
ck: fclean $(OBJS_FILES)
ck: 
	norminette | grep -v OK || :

.PHONY: all clean fclean re d ck
