# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                        :+:       :+: :+: :+:     #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by fmauguin          #+#    #+#              #
#    Updated: 2023/06/09 20:38:13 by ammah ###       ########     ########     #
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
LIBBONUSSRC			:=	ft_strlen.s \
						ft_atoi_base.s

# ---

UNITSRCDIR			:=	unit_tests
UNITOBJDIR 			:= 	units
INCLUDEDIR			:=	-I ./include

UNIT				:=	units
UNITSRC 			:= 	units.c

UNITBONUS			:=	$(UNIT)_bonus
UNITBONUSSRC 		:=	units_bonus.c

# ---

NASM				:=	nasm
CC 					:= 	gcc
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
	$(CC) -MMD -MD $(OPTFLAG) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

$(NAME)				:	$(addprefix $(OUTLIBDIR)/,$(LIBSRC:.s=.o))
	$(AR) $@ $^

$(BONUS)			:	$(addprefix $(OUTLIBDIR)/,$(LIBBONUSSRC:.s=.o))
	$(AR) $@ $^

$(UNIT) 			: 	$(LIBASM) $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.o))
	$(CC) $(OPTFLAG) -o $@ $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.o)) $(LIBFLAGS)

$(UNITBONUS) 		: 	$(LIBBONUS) $(addprefix $(OUTUNITDIR)/,$(UNITBONUSSRC:.c=.o))
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
	$(RM) $(NAME) $(LIBBONUS) $(UNIT) $(UNITBONUS)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all bonus clean fclean re debug gdb

-include	$(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.d))
