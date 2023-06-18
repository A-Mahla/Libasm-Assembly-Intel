# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 17:09:53 by amahla            #+#    #+#              #
#    Updated: 2023/06/14 19:51:34 by amahla           ###   ########.fr        #
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
						ft_strdup.s \
						ft_atoi_base.s 		\
						ft_list_push_front.s 	\
						ft_list_size.s		\
						ft_list_sort.s		\
						ft_list_remove_if.s

# ---

UNITSRCDIR			:=	src
UNITOBJDIR 			:= 	units
INCLUDEDIR			:=	-I ./include

UNIT				:=	units
UNITSRC 			:= 	units.c

# ---

NASM				:=	nasm
CC 					:= 	clang
AR 					:= 	ar rcs
RM					:=	rm -rf

NASMFLAGS			:=	-f elf64
CCFLAGS				:=	-Wall -Wextra -Werror
LIBFLAGS			:= -L . -lasm
OPTFLAG				:=

NAME				:=	$(LIBASM)

OUTDIR 				:= ./obj
OUTLIBDIR			:= $(addprefix $(OUTDIR)/, $(LIBSRCDIR))
OUTUNITDIR 			:= $(addprefix $(OUTDIR)/, $(UNITSRCDIR))

# ---

ifdef DEBUG
	OPTFLAG 		:=	-g
endif

# ---


all 				: 	$(NAME)


$(OUTLIBDIR)/%.o	:	$(LIBSRCDIR)/%.s
	@mkdir -p $(dir $@)
	$(NASM) $(NASMFLAGS) -o $@ $<

$(OUTUNITDIR)/%.o	:	$(UNITSRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -MMD -MF $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.d)) $(OPTFLAG) $(CCFLAGS) $(INCLUDEDIR) -o $@ -c $<

$(NAME)				:	$(addprefix $(OUTLIBDIR)/,$(LIBSRC:.s=.o))
	$(AR) $@ $^
	ranlib $@

$(UNIT) 			: 	$(LIBASM) $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.o))
	$(CC) $(OPTFLAG) -o $@ $(addprefix $(OUTUNITDIR)/,$(UNITSRC:.c=.o)) $(LIBFLAGS)

debug 				:
ifndef DEBUG
	$(MAKE) $(UNIT) DEBUG=1
endif

gdb					: $(UNIT)
	gdb -q $(UNIT)

clean				:
	$(RM) $(OUTDIR)

fclean				:	clean
	$(RM) $(NAME) $(UNIT)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all clean fclean re debug gdb
