
########################################################	AUX MAKEFILE	####
####	CONTROL PANEL	########################################################

CFILES		=	$(shell find . ! -name "._*" -regex ".*\\.[c]")
OFILES		=	$(notdir $(CFILES:%.c=%.o))
OBJDIR		=	../obj/

####	AUTO SETTING	########################################################
OBJECTS		:=	$(addprefix $(OBJDIR), $(notdir $(CFILES:%.c=%.o)))

####	UNDER THE HOOD	########################################################

all: $(OBJECTS) | $(OBJDIR)
	@rm $(OFILES)

$(OBJECTS): $(OFILES)
	@cp -rf $^ $(OBJDIR)

$(OFILES): $(CFILES)
	@gcc -c -Wall -Wextra -Werror $^

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf ./*.o $(OBJECTS)

fclean: clean
	@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re