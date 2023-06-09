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

LIBASM				:=	libft.a
LIBSRC				:=	ft_strlen.s

LIBBONUS			:=	libft_bonus.a
LIBBONUSSRC			:=	

# ---

UNITDIR				:=	./unit_tests
UNITOBJDIR 			:= 	units
INCLUDEDIR			:=	-I ./include

UNIT				:=	units
UNITSRC 			:= 	units.c

UNIT_BONUS			:=	$(PROGNAME)_bonus
UNIBONUSTSRC 		:=

# ---

NASM				:=	nasm
CC 					:= 	gcc
AR 					:= 	ar rcs
RM					:=	rm -rf

NASMFLAGS			:=	-f elf64
CCFLAGS				:=	-Wall -Wextra -Werror
LIBFLAGS			:= 	-L -lasm
OPTFLAG				:=

NAME				:=	$(LIBASM)
BONUS				:=	$(LIBBONUS)

OUTDIR 				:= ./obj
OUTLIBDIR			:= $(addprefix $(OUTDIR)/, $(LIBSRCDIR))
OUTUNITDIR 			:= $(addprefix $(OUTDIR)/, $(UNITOBJDIR))

# ---

ifdef DEBUG
	OPTFLAG 		:=	-g
endif

# ---


all 				: 	$(NAME)

bonus				:	$(BONUS)

$(OUTLIBDIR)/%.o		:	$(LIBSRCDIR)/%.s
	@mkdir -p $(dir $@)
	$(NASM) $(NASMFLAGS) -o $@ $<

$(UNITOUTDIR)/%.o	:	$(UNITSRCDIR)/%.c $(LIBASM)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MD $(CCFLAGS) $(OPTFLAG) $(INCLUDEDIR) $(LIBFLAG) -o $@ $<

$(NAME)				:	$(addprefix $(OUTLIBDIR)/,$(LIBSRC:.s=.o))
	$(AR) $@ $^

$(BONUS)			:	$(addprefix $(OUTLIBDIR)/,$(BONUSSRC:.s=.o))
	$(AR) $@ $^

$(UNIT) 			: 	$(NAME) $(addprefix $(OUTUNITDIR)/,$(SRC:.c=.o))
	$(CC) $(OPTFLAG) -o $@ $^

debug 				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

clean				:
	$(RM) $(OUTDIR)

fclean				:	clean
	$(RM) $(NAME) $(UNIT)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all bonus clean fclean re debug

-include	$(addprefix $(OUTUNITDIR)/,$(UNITOBJDIR:.c=.d))
