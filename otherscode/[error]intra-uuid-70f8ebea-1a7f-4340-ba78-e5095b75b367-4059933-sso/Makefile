# === MINISHELL ===

NAME							:=		minishell
CC								:=		gcc
CFLAGS							:=		-Wall -Wextra -Werror
INCLUDE							:=		-I includes

# libft
LIBFT							:=		libft.a
LIBFT_DIR						:=		libft
INCLUDE							+=		-I $(LIBFT_DIR)/includes
LIBFT_FLAGS						:=		-L $(LIBFT_DIR) -lft

# readline
INCLUDE							+=		-I $(shell brew --prefix readline)/include
LDFLAGS							:=		-L $(shell brew --prefix readline)/lib -lreadline -lhistory

# --- SRC FILES ----
SRC_DIR							:=		./src
SRC_FILES						:=		$(addprefix $(SRC_DIR)/, \
										main.c \
										minishell.c \
)

INPUT_DIR						:=		./src/input
INPUT_FILES						:=		$(addprefix $(INPUT_DIR)/, \
										input.c \
										lex_lexer.c \
										lex_tokenize.c \
										prs_parser.c \
										prs_syntax.c \
										expansion.c \
										exp_expansion.c \
										exp_expand_str.c \
										exp_decompos_str.c \
										heredoc.c \
										heredoc_util.c \
)


EXEC_DIR						:=		./src/exec
EXEC_FILES						:=		$(addprefix $(EXEC_DIR)/, \
										exec_execution.c \
										exec_multiple_command.c \
										exec_run.c \
										exec_heredoc.c \
										exec_utils.c \
										set_redirect.c \
										ft_execvp.c \
)

# mini_env.c
BUILTINS_DIR					:=		./src/builtins
BUILTINS_FILES					:=		$(addprefix $(BUILTINS_DIR)/, \
										mini_cd.c \
										mini_cd_launch.c \
										mini_echo.c \
										mini_pwd.c \
										mini_exit.c \
										mini_env.c \
										mini_export.c \
										mini_unset.c \
)

SHELL_INFO_DIR					:=		./src/shell_info
SHELL_INFO_FILES				:=		$(addprefix $(SHELL_INFO_DIR)/, \
										shell_info.c \
										shell_info_sig.c \
										shell_info_cwd.c \
										shell_info_interactive.c \
										cmd.c \
										cmd_utils.c \
										redirect_info.c \
										redirect_info_utils.c \
										token.c \
)

ENVIRONMENT_DIR					:=		./src/environment
ENVIRONMENT_FILES				:=		$(addprefix $(ENVIRONMENT_DIR)/, \
										env_setter.c \
										env_getter.c \
										env_utils.c \
										env_utils2.c \
										env_shlvl.c \
)

ENVIRONMENT_DLST_DIR			:=		./src/environment/env_dlst
ENVIRONMENT_DLST_FILES			:=		$(addprefix $(ENVIRONMENT_DLST_DIR)/, \
										env_dlst.c \
										env_dlst_utils.c \
)

ENVIRONMENT_TUPLE_DIR			:=		./src/environment/env_tuple
ENVIRONMENT_TUPLE_FILES			:=		$(addprefix $(ENVIRONMENT_TUPLE_DIR)/, \
										env_tuple.c \
										env_tuple_utils.c \
)

SIGNAL_DIR						:=		./src/signal
SIGNAL_FILES					:=		$(addprefix $(SIGNAL_DIR)/, \
										signal.c \
)

UTILS_DIR						:=		./src/utils
UTILS_FILES						:=		$(addprefix $(UTILS_DIR)/, \
										utl_utils.c \
										utl_env.c \
										utl_path_utils.c \
										utl_error.c \
										is_builtin.c \
										wrap_syscalls.c \
										utl_metastr.c \
										utl_libft_utils.c \
										utl_readline_utils.c \
)


# --- SRC & OBJS ---
# VPATH : all src dirs
VPATH				:=		$(SRC_DIR) \
							$(LEXER_DIR) \
							$(INPUT_DIR) \
							$(PARSER_DIR) \
							$(EXPANSION_DIR) \
							$(EXEC_DIR) \
							$(BUILTINS_DIR) \
							$(SHELL_INFO_DIR) \
							$(ENVIRONMENT_DIR) \
							$(ENVIRONMENT_DLST_DIR) \
							$(ENVIRONMENT_TUPLE_DIR) \
							$(SIGNAL_DIR) \
							$(UTILS_DIR) \
							$(DEBUG_DIR)

# SRC : all src files
SRC					:=		$(SRC_FILES) \
							$(LEXER_FILES) \
							$(INPUT_FILES) \
							$(PARSER_FILES) \
							$(EXPANSION_FILES) \
							$(EXEC_FILES) \
							$(BUILTINS_FILES) \
							$(SHELL_INFO_FILES) \
							$(ENVIRONMENT_FILES) \
							$(ENVIRONMENT_DLST_FILES) \
							$(ENVIRONMENT_TUPLE_FILES) \
							$(SIGNAL_FILES) \
							$(UTILS_FILES) \
							$(DEBUG_FILES)

OBJS_DIR			:=		./_objs

OBJS				:=		$(addprefix $(OBJS_DIR)/, $(notdir $(SRC:.c=.o)))



# --- COLOR ---
RESET				:=		\033[0m
RED					:=		\033[0;31m
GREEN				:=		\033[0;32m
YELLOW				:=		\033[0;33m
BLUE				:=		\033[0;34m
CYAAN				:=		\033[0;36m
WHITE				:=		\033[0;37m



# --- PERCENTAGE ---
T					=		$(words $(OBJS))
N					=		0
C					=		$(words $N)${eval N+= 1}
PERCENTAGE			=		"`expr $C '*' 100 / $T`%"
MESSAGE				=		"%-100b\r" "$(YELLOW)Compiling $(NAME) ... $(PERCENTAGE)$(RESET)"

# --- MAKE ---

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) Makefile
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT_FLAGS) $(LDFLAGS) -o $(NAME)
	@printf "\n$(GREEN)CREATED $(NAME)$(RESET)\n"

# mkdir $(OBJS_DIR)
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# make .o files
$(OBJS_DIR)/%.o: %.c Makefile includes/*
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	@printf $(MESSAGE)

# make libft.a
$(LIBFT):
	@$(MAKE) -e -C $(LIBFT_DIR)

clean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "$(RED)CLEAN  : rm -f $(NAME) objs$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)FCLEAN : rm -f $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re

# print:
# 	@printf '\n'
# 	@printf 'CC          : %s\n' "$(CC)"
# 	@printf 'CFLAGS      : %s\n' "$(CFLAGS)"
# 	@printf 'INCLUDE     : %s\n' "$(INCLUDE)"
# 	@printf 'LIBFT_FLAGS : %s\n' "$(LIBFT_FLAGS)"
# 	@printf 'LDFLAGS     : %s\n' "$(LDFLAGS)"
# 	@printf '\n'

# make $(NAME)
# $(NAME): print $(LIBFT) $(OBJS_DIR) $(OBJS) Makefile includes/*
# 	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT_FLAGS) $(LDFLAGS) -o $(NAME)
# 	@printf "\n$(GREEN)CREATED $(NAME)$(RESET)\n"

# d: export CFLAGS += -D SANITIZER=1 -g3 -fsanitize=address
# d: re

# dd: export CFLAGS += -D SANITIZER=1 -g3 \
# 						-fsanitize=address \
# 						-fsanitize=undefined \
# 						-fsanitize=integer
# dd: re


# # -ftrivial-auto-var-init=pattern
# # -fsanitize-address-use-after-return=always : mac unknown argument
# ddd: export CFLAGS += -D SANITIZER=1 -g3 \
# 						-Wtautological-compare -Wsign-compare \
# 						-gfull -fstandalone-debug -gdwarf-5 -gz \
# 						-fno-sanitize-recover=all \
# 						-fsanitize=address \
# 						-fsanitize=undefined \
# 						-fsanitize=integer \
# 						-fsanitize=bounds \
# 						-fsanitize-address-use-after-scope \
# 						-fsanitize-address-use-odr-indicator \
# 						-fno-omit-frame-pointer \
# 						-fno-optimize-sibling-calls \
# 						-fno-common
# ddd: re

# # detect_leaks : mac not support
# drun: ASAN_OPTIONS = UBSAN_OPTIONS='print_stacktrace=1: \
# 									abort_on_error=0: \
# 									strict_init_order=1: \
# 									detect_stack_use_after_return=1: \
# 									strict_string_checks=1: \
# 									detect_invalid_pointer_pairs=2: \
# 									use_odr_indicator=1: \
# 									abort_on_error=0'
# drun:
# 	@echo $(subst $() ,,$(ASAN_OPTIONS))
# 	@$(subst $() ,,$(ASAN_OPTIONS)) ./$(NAME)

# # Run static analysis.
# s: export CFLAGS += --analyze
# s: clean
# s: print $(OBJS_DIR) $(OBJS) $(LIBFT) Makefile includes/*
# s: clean

# # 
# l: CFLAGS += -D LEAKS=1
# l: re

# nof: CFLAGS = 
# nof: all

# test: docker_test

# PHONY	:=	all clean fclean re d dd ddd drun s l nof test



# # ----- DOCKER -----

# DOCKER_FILE_DIR			:=		docker
# DOCKER_IMG_NAME			:=		img-minishell
# DOCKER_CTR_NAME			:=		ctr-minishell
# DOCKER_CTR_WORK_DIR		:=		/work

# docker: IS_DOCKER_IMG_EXIST := $(shell ! docker images | grep $(DOCKER_IMG_NAME) > /dev/null; echo $$?)
# docker: IS_DOCKER_CTR_EXIST := $(shell ! docker ps -a | grep $(DOCKER_CTR_NAME) > /dev/null; echo $$?)
# docker:
# 	@if [ $(IS_DOCKER_IMG_EXIST) -eq 0 ]; then \
# 		docker build -t $(DOCKER_IMG_NAME) $(DOCKER_FILE_DIR); \
# 	else \
# 		echo "docker img exist"; \
# 	fi

# 	@if [ $(IS_DOCKER_CTR_EXIST) -eq 0 ]; then \
# 		docker create --name $(DOCKER_CTR_NAME) $(DOCKER_IMG_NAME); \
# 	else \
# 		echo "docker ctr exist"; \
# 	fi

# docker_rm:
# 	docker stop $(DOCKER_CTR_NAME) || :
# 	docker rm $(DOCKER_CTR_NAME) || :
# 	docker rmi $(DOCKER_IMG_NAME) || :

# docker_reset:
# 	docker stop $(DOCKER_CTR_NAME) || :
# 	docker rm $(DOCKER_CTR_NAME) || :
# 	docker create --name $(DOCKER_CTR_NAME) $(DOCKER_IMG_NAME)

# docker_re: docker_rm docker

# docker_it: docker_cp
# 	docker start $(DOCKER_CTR_NAME)
# 	docker exec -it $(DOCKER_CTR_NAME) "/bin/bash"

# docker_cp:
# 	docker start $(DOCKER_CTR_NAME)
# 	docker exec $(DOCKER_CTR_NAME) /bin/bash -c "mkdir -p $(DOCKER_CTR_WORK_DIR)"
# 	docker exec $(DOCKER_CTR_NAME) /bin/bash -c "rm -rf $(DOCKER_CTR_WORK_DIR)/*"
# 	docker cp "debug" $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)
# 	docker cp "includes" $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)
# 	docker cp "libft" $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)
# 	docker cp "src" $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)
# 	docker cp "Makefile" $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)
# 	docker cp test $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)
# 	docker cp docs/Doxyfile $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)

# define exec_with_docker
# 	docker exec -it $(DOCKER_CTR_NAME) /bin/bash -c "cd $(DOCKER_CTR_WORK_DIR) && $1"
# endef

# DO_TEST_FILES		:=	test_case/_on_going.txt
# # DO_TEST_FILES		:=	test_case/_on_going.txt test_case/builtin_test/builtin_echo.txt

# DOCKER_MAKE_OPT		:=	

# docker_test: docker_cp
# 	$(call exec_with_docker, make fclean && make $(DOCKER_MAKE_OPT) CC=clang)
# 	$(call exec_with_docker, cd $(DOCKER_CTR_WORK_DIR)/test && python3 -u minishell_tester.py $(DO_TEST_FILES))
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_list.txt test/ko_list.txt
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_log.txt test/ko_log.txt
# 	@echo
# 	cat test/ko_list.txt
# 	@echo
# 	@echo
# 	@echo "Look at the test/ko_log.txt"
# 	@echo

# docker_dtest: DOCKER_MAKE_OPT	+=	d
# docker_dtest: docker_test

# docker_all_test: DO_TEST_FILES = $(shell cd test && find test/test_case -name \*.txt)
# docker_all_test: docker_test

# docker_all_dtest: DOCKER_MAKE_OPT	+=	d
# docker_all_dtest: DO_TEST_FILES = $(shell cd test && find test/test_case -name \*.txt)
# docker_all_dtest: docker_test


# #docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_list.txt test/ko_list.txt
# rand: docker_cp
# 	$(call exec_with_docker, make fclean && make $(DOCKER_MAKE_OPT) CC=clang)
# 	$(call exec_with_docker, cd $(DOCKER_CTR_WORK_DIR)/test && python3 -u minishell_tester.py rand)
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_log.txt test/ko_log.txt
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_log.txt test/ko_list.txt
# 	@echo
# 	cat test/ko_list.txt
# 	@echo
# 	@echo 
# 	@echo "Look at the test/ko_log.txt"
# 	@echo

# drand: DOCKER_MAKE_OPT	+=	d
# drand: docker_cp
# 	$(call exec_with_docker, make fclean && make $(DOCKER_MAKE_OPT) CC=clang)
# 	$(call exec_with_docker, cd $(DOCKER_CTR_WORK_DIR)/test && python3 -u minishell_tester.py rand)
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_log.txt test/ko_log.txt
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/test/ko_log.txt test/ko_list.txt
# 	@echo
# 	cat test/ko_list.txt
# 	@echo
# 	@echo
# 	@echo "Look at the test/ko_log.txt"
# 	@echo

# DOCKER_PHONY	:=	docker docker_rm docker_reset docker_re docker_it docker_cp \
# 					docker_test docker_dtest docker_alltest docker_alldtest



# # ----- dox -----

# dox: docker_cp
# 	docker exec $(DOCKER_CTR_NAME) /bin/bash -c "cd $(DOCKER_CTR_WORK_DIR) && doxygen"
# 	docker cp $(DOCKER_CTR_NAME):$(DOCKER_CTR_WORK_DIR)/html docs
# 	@echo "$(GREEN)Look at the "docs/html/index.html" file.$(RESET)"

# opn_dox:
# 	open -a "Safari" docs/html/index.html

# DOX_PHONY		:=	dox opn_dox



# # --- help ---

# help:
# 	@echo "PHONY        : $(PHONY)"
# 	@echo "DOCKER_PHONY : $(DOCKER_PHONY)"
# 	@echo "DOX_PHONY    : $(DOX_PHONY)"



# .PHONY: $(PHONY) $(DOCKER_PHONY) $(DOX_PHONY)
