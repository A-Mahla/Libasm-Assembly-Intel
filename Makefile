# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                        :+:       :+: :+: :+:     #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by fmauguin          #+#    #+#              #
#    Updated: 2023/06/09 20:16:59 by ammah ###       ########     ########     #
#                                                                              #
# **************************************************************************** #

# ---

LIBSRCDIR			:=	./src
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

OUTDIR				:= $(addprefix obj/, $(LIBSRCDIR))
OUTUNITDIR 			:= $(addprefix obj/, $(UNITOBJDIR))

# ---

ifdef DEBUG
	OPTFLAG 		:=	-g
endif

# ---


all 				: 	$(NAME)

bonus				:	$(BONUS)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.s
	@mkdir -p $(dir $@)
	$(NASM) $(NASMFLAGS) -o $@ $<

$(UNITOUTDIR)/%.o	:	$(UNITSRCDIR)/%.c $(LIBASM)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MD $(CCFLAGS) $(OPTFLAG) $(INCLUDEDIR) $(LIBFLAG) -o $@ $<

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRC:.s=.o))
	$(AR) $@ $^

$(BONUS)			:	$(addprefix $(OUTDIR)/,$(BONUSSRC:.s=.o))
	$(AR) $@ $^

$(UNIT) 			: 	$(NAME) $(addprefix $(OUTUNITDIR)/,$(SRC:.c=.o))
	$(CC) $(OPTFLAG) -o $@ $^

debug 				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

clean				:
	$(RM) -rf $(OBJDIR) $(BONUSOUTDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME) $(PROGNAME_BONUS) $(DEBUGNAME) $(BONUSDEBUGNAME) $(FLORANNAME)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all bonus clean fclean re debug

-include	$(addprefix $(OUTUNITDIR)/,$(UNITOBJDIR:.c=.d))