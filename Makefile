
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		:=	ft_ssl
BUILDDIR	:=	build
INCLDIR		:=	include
CDIR		:=	source
ODIR		:=	obj
LIB			:=	lib
LDIR		:=	$(LIB)/libft
LINCL		:=	$(LDIR)/include
LIBFT		:=	$(LDIR)/libft.a
CFILES		:=	$(shell find $(CDIR) ! -name "._*" -regex ".*\\.[c]")
HFILES		:=	$(shell find $(INCLDIR) ! -name "._*" -regex ".*\\.[h]")
LFILES		:=	$(shell find $(dir $(LIBFT)) ! -name "._*" -regex ".*\\.[c]")
INCLUDE		:=	-I $(abspath $(INCLDIR)) -I $(abspath $(LINCL))
FLAGS		:=	$(INCLUDE) -Wall -Wextra
FLAGS		:=	$(FLAGS) -Werror

####	DEBUGGING		########################################################

FLAGS		:=	$(INCLUDE) -Wall -Wextra -g

####	AUTO SETTING	########################################################

ODIR		:=	$(addprefix $(BUILDDIR)/, $(ODIR))
OBJECTS		:=	$(addprefix $(ODIR)/, $(notdir $(CFILES:%.c=%.o)))

####	UNDER THE HOOD	########################################################

all: $(NAME)

#test: test.c | $(LIBFT)
#	@gcc -g $(INCLUDE) $(LIBFT) $^

#test: test.c source/md5/md5.c $(LFILES)
test: test.c source/input/open_fd.c $(LFILES)
	@gcc -o x.test -g $(INCLUDE) $^

$(NAME): $(LIBFT) $(OBJECTS)
	@gcc $(FLAGS) -o $@ -L $(<D) -lft $(OBJECTS)

$(OBJECTS): $(CFILES) | $(ODIR)
	@cd $(@D); gcc -c $(FLAGS) $(abspath $^)
#	@cd $(@D); $(foreach srcf, $(abspath $^), gcc -c $(FLAGS) $(srcf);)

$(LIBFT): | $(ODIR)
	@make -C $(@D)

$(ODIR):
	@mkdir -p $@

clean:
	@rm -rf $(ODIR);\
		make clean -C $(dir $(LIBFT))

fclean:
	@rm -rf $(BUILDDIR);\
		make fclean -C $(dir $(LIBFT))

re: fclean all

.PHONY: clean fclean all re test