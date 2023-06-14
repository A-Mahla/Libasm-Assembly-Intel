# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by fmauguin          #+#    #+#              #
#    Updated: 2023/06/14 16:54:45 by amahla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---

LIBSRCDIR			:=	src
LIBOBJDIR			:=	libasm

LIBASM				:=	libasm.a
LIBSRC				:=	ft_strlen.s \
						ft_strcpy.s \
						ft_strcmp.s \
						ft_write.s  \
						ft_read.s   \
						ft_strdup.s

LIBBONUS			:=	libasm_bonus.a
LIBBONUSSRC			:=	ft_strlen.s 				\
						ft_strcmp.s 				\
						ft_atoi_base_bonus.s 		\
						ft_list_push_front_bonus.s 	\
						ft_list_size_bonus.s		\
						ft_list_sort_bonus.s		\
						ft_list_remove_if_bonus.s

# ---

UNITSRCDIR			:=	unit_tests
UNITOBJDIR 			:= 	units
INCLUDEDIR			:=	-I ./include

UNIT				:=	units
UNITSRC 			:= 	units.c

UNITBONUS			:=	$(UNIT)_bonus
UNITBONUSSRC 		:=	units_bonus.c

# ---

ACEUNIT_HOME		:=	./aceunit
ACEUNIT_REPO		:=	git@github.com:christianhujer/aceunit.git
ACEUNIT_LIBRARY		:=	$(ACEUNIT_HOME)/lib/libaceunit-abort.a
ACE_INCLUDES		:= -I $(ACEUNIT_HOME)/include

# ---

NASM				:=	nasm
CC 					:= 	clang
AR 					:= 	ar rcs
RM					:=	rm -rf

NASMFLAGS			:=	-f elf64
CCFLAGS				:=	-Wall -Wextra -Werror
LIBFLAGS			:= -L . -lasm
LIBBONUSFLAGS		:= -L . -lasm_bonus
OPTFLAG				:=

NAME				:=	$(LIBASM)
BONUS				:=	$(LIBBONUS)

OUTDIR 				:= ./obj
OUTLIBDIR			:= $(addprefix $(OUTDIR)/, $(LIBSRCDIR))
OUTUNITDIR 			:= $(addprefix $(OUTDIR)/, $(UNITSRCDIR))

# ---

ifdef DEBUG
	OPTFLAG 		:=	-g
endif

# ---


all 				: 	$(NAME)

bonus				:	$(BONUS)

$(OUTLIBDIR)/%.o	:	$(LIBSRCDIR)/%.s
	@mkdir -p $(dir $@)
	$(NASM) $(NASMFLAGS) -o $@ $<

$(OUTUNITDIR)/%.o	:	$(UNITSRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -MMD -MF $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.d)) $(OPTFLAG) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

$(NAME)				:	$(addprefix $(OUTLIBDIR)/,$(LIBSRC:.s=.o))
	$(AR) $@ $^
	ranlib $@

$(BONUS)			:	$(addprefix $(OUTLIBDIR)/,$(LIBBONUSSRC:.s=.o))
	$(AR) $@ $^
	ranlib $@

$(ACEUNIT_HOME)		:
	@git clone $(ACEUNIT_REPO) > /dev/null 2>&1

$(ACEUNIT_LIBRARY): $(ACEUNIT_HOME)
	@$(MAKE) -C $(dir $(ACEUNIT_LIBRARY)) > /dev/null 2>&1

$(UNIT) 			: 	$(ACEUNIT_LIBRARY) $(LIBASM) $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.o))
	$(CC) $(OPTFLAG) -o $@ $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.o)) $(LIBFLAGS)

$(UNITBONUS) 		: 	$(ACEUNIT_LIBRARY) $(LIBBONUS) $(addprefix $(OUTUNITDIR)/,$(UNITBONUSSRC:.c=.o))
	$(CC) $(OPTFLAG) -o $@ $(addprefix $(OUTUNITDIR)/,$(UNITBONUSSRC:.c=.o)) $(LIBBONUSFLAGS)

debug 				:
ifndef DEBUG
	$(MAKE) $(UNIT) DEBUG=1
endif

gdb					: $(UNIT)
	gdb -q $(UNIT)

clean				:
	$(RM) $(OUTDIR)

fclean				:	clean
	$(RM) $(NAME) $(LIBBONUS) $(UNIT) $(UNITBONUS) $(ACEUNIT_HOME) $(ACEUNIT_LIBRARY)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all bonus clean fclean re debug gdb

-include	$(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.d))
