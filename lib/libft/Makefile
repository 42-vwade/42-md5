
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		=	libft.a
BUILDDIR	=	build
INCLDIR		=	include
CDIR		=	source
ODIR		=	obj
CFILES		:=	$(shell find $(CDIR) ! -name "._*" -regex ".*\\.[c]")
HFILES		:=	$(shell find $(INCLDIR) ! -name "._*" -regex ".*\\.[h]")
CC			:=	gcc
AR			:=	ar rc
IFLAGS		:=	-I $(abspath $(INCLDIR))
CFLAGS		:=	-c $(IFLAGS) -Wall -Werror -Wextra
FLAGS		:=	$(IFLAGS) -Wall -Wextra
FLAGS		:=	$(FLAGS) -Werror

####	DEBUGGING		########################################################

FLAGS		:=	$(IFLAGS) -Wall -Wextra -g

####	AUTO SETTING	########################################################

ODIR		:=	$(addprefix $(BUILDDIR)/, $(ODIR))
OBJECTS		:=	$(addprefix $(ODIR)/, $(notdir $(CFILES:%.c=%.o)))

####	FONT FORMAT		########################################################

FM0 = \033[0m#		NO FORMAT
FMB = \033[1m#		BOLD FONT
FMR = \033[31m#		RED COLOR
FMM = \e[35m#		MAGENTA COLOR

####	UNDER THE HOOD	########################################################

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $@ $^
	@ranlib $@

$(OBJECTS): $(CFILES) | $(ODIR)
	@cd $(ODIR); $(CC) $(CFLAGS) $(abspath $^)

$(ODIR): $(BUILDDIR)
	@mkdir -p $@

$(BUILDDIR):
	@mkdir -p $@

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(BUILDDIR) $(NAME)

re: fclean all

.PHONY: clean fclean all re
