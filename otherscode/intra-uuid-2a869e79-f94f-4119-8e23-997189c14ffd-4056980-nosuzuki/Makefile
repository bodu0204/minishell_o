NAME		:= minishell
SHELL		:= /bin/bash

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -MMD -MP
IOPTIONS	= $(addprefix -I , $(INCLUDES))
LIBS		:= -lreadline -lft

RL_LIBPATH	= $(shell cat .rl_info 2>/dev/null| grep 'export LDFLAGS=' | awk -F '=' '{print $$2}' | tr -d '"' )
RL_INCLUDE	= $(shell cat .rl_info 2>/dev/null| grep 'export CPPFLAGS=' | awk -F '=' '{print $$2}' | tr -d '"')
RL_CACHE	= .rl_info

SRCDIR		:= srcs
OBJDIR		:= ./obj
LIBFTDIR	:= ./libft
LIBFT		:= $(LIBFTDIR)/libft.a

INCLUDE		:= ./includes
LIBINCLUDE	:= $(LIBFTDIR)/includes
INCLUDES	:= $(INCLUDE) $(LIBINCLUDE)

DIR1		:= $(SRCDIR)/lexer
DIR2		:= $(SRCDIR)/error
DIR3		:= $(SRCDIR)/debug
DIR4		:= $(SRCDIR)/parser
DIR5		:= $(SRCDIR)/heredoc
DIR6		:= $(SRCDIR)/execution
DIR7		:= $(SRCDIR)/wrapper
DIR8		:= $(SRCDIR)/expansion
DIR9		:= $(SRCDIR)/utils
DIRA		:= $(SRCDIR)/hooks
DIRB		:= $(SRCDIR)/signal
DIRC		:= $(SRCDIR)/variable
DIRD		:= $(SRCDIR)/builtin
DIRE		:= $(SRCDIR)/cache
DIRF		:= $(SRCDIR)/path
DIRG		:= $(SRCDIR)/del

MAIN		:=\
	srcs/main.c\
	srcs/run.c\

SRC1	=\
	srcs/lexer/chartype.c\
	srcs/lexer/lexer.c\
	srcs/lexer/tokenizer.c\
	srcs/lexer/utils.c\

SRC2	=\
	srcs/error/or_exit.c\
	srcs/error/put_nocurrent.c\
	srcs/error/puterr.c\
	srcs/error/puterrs.c\

SRC3	=\
	srcs/debug/exp_print.c\
	srcs/debug/lex_print.c\
	srcs/debug/parse_print.c\

SRC4	=\
	srcs/parser/append_data.c\
	srcs/parser/error.c\
	srcs/parser/parse1.c\
	srcs/parser/parse2.c\
	srcs/parser/parser.c\
	srcs/parser/redir.c\
	srcs/parser/utils.c\

SRC5	=\
	srcs/heredoc/error.c\
	srcs/heredoc/heredoc.c\
	srcs/heredoc/input_util.c\
	srcs/heredoc/join.c\

SRC6	=\
	srcs/execution/cmd_path.c\
	srcs/execution/execution.c\
	srcs/execution/find_cmd.c\
	srcs/execution/invalid_cmd_err.c\
	srcs/execution/launcher.c\
	srcs/execution/pipe_get.c\
	srcs/execution/pipeline.c\
	srcs/execution/redir1.c\
	srcs/execution/redir2.c\
	srcs/execution/search_builtin.c\
	srcs/execution/setup_excution.c\
	srcs/execution/stdfd.c\
	srcs/execution/wait.c\

SRC7	=\
	srcs/wrapper/ft_close.c\
	srcs/wrapper/ft_dup.c\
	srcs/wrapper/ft_dup2.c\
	srcs/wrapper/ft_execve.c\
	srcs/wrapper/ft_fork.c\
	srcs/wrapper/ft_getcwd.c\
	srcs/wrapper/ft_open.c\
	srcs/wrapper/ft_pipe.c\
	srcs/wrapper/ft_waitpid.c\


SRC8	=\
	srcs/expansion/del.c\
	srcs/expansion/exp_ctype.c\
	srcs/expansion/expand_var.c\
	srcs/expansion/expansion.c\
	srcs/expansion/insert_cmds.c\
	srcs/expansion/join_tokens.c\
	srcs/expansion/split_by_space.c\
	srcs/expansion/tokenize..c\
	srcs/expansion/tokenize_quote.c\
	srcs/expansion/tokenize_var.c\
	srcs/expansion/utils.c\

SRC9	=\
	srcs/utils/strtol.c\

SRCA	=\
	srcs/hooks/hooks.c\

SRCB	=\
	srcs/signal/sig_utils.c\

SRCC	=\
	srcs/variable/exists_env.c\
	srcs/variable/get.c\
	srcs/variable/get_int.c\
	srcs/variable/hash_util.c\
	srcs/variable/init.c\
	srcs/variable/set.c\
	srcs/variable/set_cwd.c\
	srcs/variable/set_int.c\
	srcs/variable/shlvl.c\
	srcs/variable/utils.c\

SRCD	=\
	srcs/builtin/cd/cd.c\
	srcs/builtin/cd/del.c\
	srcs/builtin/cd/retry_cd.c\
	srcs/builtin/cd/try_cd_normalize.c\
	srcs/builtin/cd/try_cd_to.c\
	srcs/builtin/echo/echo.c\
	srcs/builtin/env/env.c\
	srcs/builtin/exit/exit.c\
	srcs/builtin/export/export.c\
	srcs/builtin/export/print.c\
	srcs/builtin/export/var.c\
	srcs/builtin/getoptions.c\
	srcs/builtin/hash/hash.c\
	srcs/builtin/nop/nop.c\
	srcs/builtin/put_cmd_type.c\
	srcs/builtin/pwd/pwd.c\
	srcs/builtin/type/type.c\
	srcs/builtin/unset/unset.c\
	srcs/builtin/which/which.c\

SRCE	=\
	srcs/cache/cache.c\

SRCF	=\
	srcs/path/create_absolute.c\
	srcs/path/find_from_path.c\

SRCG	=\
	srcs/del/cd_del.c\
	srcs/del/cwd_del.c\
	srcs/del/etok_del.c\
	srcs/del/exec_del.c\
	srcs/del/exp_del.c\
	srcs/del/hdoc_del.c\
	srcs/del/lex_del.c\
	srcs/del/parse_del.c\
	srcs/del/proc_del.c\
	srcs/del/redir_del.c\


SRCS		:= $(MAIN)$(SRC1)$(SRC2)$(SRC3)$(SRC4)$(SRC5)$(SRC6)$(SRC7)$(SRC8)$(SRC9)$(SRCA)$(SRCB)$(SRCC)$(SRCD)$(SRCE)$(SRCF)$(SRCG)
OBJS		:= $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCS:.c=.o))
DEPENDS		:= $(OBJS:.o=.d)

PURPLE		:= \033[1;35m
GREEN		:= \033[1;32m
RESET		:= \033[0;39m

# ifdef WITH_BONUS
# NAME	= philo_bonus
# OBJS	= $(shell basename -a $(B_SRCS:.c=.o) $(LIBSRCS:.c=.o) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# DEPENDS	= $(shell basename -a $(B_SRCS:.c=.d) $(LIBSRCS:.c=.d) | awk -v o=$(OBJDIR) '{print o"/"$$0}')
# endif

all		: rl _libft $(NAME)

-include $(DEPENDS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)/$(*D)
	@$(CC) $(CFLAGS) $(RL_INCLUDE) $(IOPTIONS) -c $< -o $@
	@echo -e "	""$(GREEN)$@$(RESET)"

$(NAME)	: $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(IOPTIONS) $(RL_INCLUDE) $(RL_LIBPATH) -L$(LIBFTDIR) $(OBJS) $(LIBS) -o $@
	@echo -e "\n$(PURPLE) build	$(GREEN)$@$(RESET)"

rl	: $(RL_CACHE)

ifeq ($(shell uname),Darwin)
$(RL_CACHE) :
	brew install readline
	brew info readline > $(RL_CACHE)
else
$(RL_CACHE) :
endif

_libft:
	@$(MAKE) -C $(LIBFTDIR)

$(LIBFT): _libft

clean	: rm_reloc
#	# @make b_clean WITH_BONUS=1

fclean	: clean rm_exec
#	@make b_fclean WITH_BONUS=1

bonus	: $(NAME)
# 	@make WITH_BONUS=1

b_clean	: rm_reloc

b_fclean: rm_exec

rm_reloc:
	$(RM) -r $(OBJDIR) $(LIBFTDIR)/$(OBJDIR)

rm_exec	:
	$(RM) $(NAME) $(LIBFTDIR)/libft.a

add		:
	bash header.sh "$(DIR1)" $(INCLUDE)/lexer.h
	bash header.sh "$(DIR2)" $(INCLUDE)/error.h
# bash header.sh "$(DIR3)" $(INCLUDE)/debug.h
	bash header.sh "$(DIR4)" $(INCLUDE)/parser.h
	bash header.sh "$(DIR5)" $(INCLUDE)/heredoc.h
	bash header.sh "$(DIR6)" $(INCLUDE)/execution.h
	bash header.sh "$(DIR7)" $(INCLUDE)/wrapper.h
	bash header.sh "$(DIR8)" $(INCLUDE)/expansion.h
	bash header.sh "$(DIR9)" $(INCLUDE)/utils.h
	bash header.sh "$(DIRA)" $(INCLUDE)/hooks.h
	bash header.sh "$(DIRB)" $(INCLUDE)/signals.h
	bash header.sh "$(DIRC)" $(INCLUDE)/variable.h
	bash header.sh "$(DIRD)" $(INCLUDE)/builtin.h
	bash header.sh "$(DIRE)" $(INCLUDE)/cache.h
	bash header.sh "$(DIRF)" $(INCLUDE)/path.h
	bash header.sh "$(DIRG)" $(INCLUDE)/del.h
# bash header.sh "$(DIR2)" $(INCLUDE)/headername2.h
# bash header.sh "$(DIR3)" $(INCLUDE)/headername3.h
	bash make.sh $(DIR1) SRC1
	bash make.sh $(DIR2) SRC2
	bash make.sh $(DIR3) SRC3
	bash make.sh $(DIR4) SRC4
	bash make.sh $(DIR5) SRC5
	bash make.sh $(DIR6) SRC6
	bash make.sh $(DIR7) SRC7
	bash make.sh $(DIR8) SRC8
	bash make.sh $(DIR9) SRC9
	bash make.sh $(DIRA) SRCA
	bash make.sh $(DIRB) SRCB
	bash make.sh $(DIRC) SRCC
	bash make.sh $(DIRD) SRCD
	bash make.sh $(DIRE) SRCE
	bash make.sh $(DIRF) SRCF
	bash make.sh $(DIRG) SRCG
# bash make.sh $(DIR2) SRC2
# bash make.sh $(DIR3) SRC3

re		: fclean all

debug	: CFLAGS += -g -fsanitize=address
debug	: re

TESTDIR		= tests
GTESTDIR	= $(TESTDIR)/googletest
GTESTLIB	= $(GTESTDIR)/gtest.a
TESTCASES	= $(wildcard $(TESTDIR)/$(F)*test.cpp) $(TESTDIR)/test_util.cpp
TESTOBJS	= $(filter-out %main.o, $(OBJS))
TESTLIBS	= -lpthread -L$(LIBFTDIR) $(LIBS)
TESTER		= tester

$(GTESTLIB):
	$(MAKE) -C $(TESTDIR)

$(TESTER)	: $(NAME) $(GTESTLIB) $(TESTCASES)
	clang++ -I$(GTESTDIR) $(IOPTIONS) $(GTESTLIB) $(TESTCASES) $(TESTOBJS) $(TESTLIBS) -o $@

gen		:
	python3 $(TESTDIR)/casemaker.py

test	: $(TESTER)
	./$<

leak	: $(TESTER)
	valgrind --leak-check=full ./$<

cinorm	:
	@norminette includes libft $(shell find srcs -mindepth 1 -type d -not -name debug) \
		| grep -v 'Missing or' \
		| grep -v 'WRONG_SCOPE_COMMENT' \
		| grep -v 'TOO_MANY_FUNCS' \
		| grep -v ': OK!' \
		| tee /dev/stderr \
		| grep 'Error: ' > /dev/null; \
		if [ $$? -eq 0 ]; then \
			exit 1; \
		else \
			printf '$(GREEN)%s\n$(RESET)' 'Norm: OK!'; \
		fi

norm	:
	@norminette includes libft srcs \
		| grep -v ': OK!'; \
		if [ $$? -eq 0 ]; then \
			exit 1; \
		else \
			printf '$(GREEN)%s\n$(RESET)' 'Norm: OK!'; \
		fi

.PHONY	: all clean fclean re bonus add norm rm_exec rm_reloc b_clean b_fclean head _libft test rl