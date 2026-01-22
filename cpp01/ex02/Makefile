#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

MAKE	= make -C
SHELL	:= bash

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME			= Brain

###	Message Vars
_NAME			= [$(MAG)cpp$(D)]
_SUCCESS		= [$(GRN)Success!$(D)]
_INFO			= [$(BLU)INFO$(D)]
_SEP			= ======================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= src
BUILD_PATH		= .build
TEMP_PATH		= .temp

### Files Source
FILES += main.cpp

### Paths
SRC		= $(addprefix $(SRC_PATH)/, $(FILES))
OBJS	= $(addprefix $(BUILD_PATH)/, $(FILES:.cpp=.o))

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CPP				= c++
CPPFLAGS		= -std=c++98 -Iinc
CFLAGS			= -Wall -Wextra -Werror -g

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

RM		= rm -rf
AR		= ar rcs
MKDIR_P = mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: $(BUILD_PATH) $(NAME)

$(NAME): $(BUILD_PATH) $(OBJS)
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CPP) $(CPPFLAGS) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL):D$(D)]"

-include $(BUILD_PATH)/%.d

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo -n "$(MAG)#$(D) "
	$(CPP) $(CPPFLAGS) -MMD -MP -c -g $< -o $@

$(BUILD_PATH):
	@$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	@$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(CYA)$(TEMP_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

valgrind: all $(NAME) $(TEMP_PATH)
	"valgrind $(VAL_ARGS) $(VAL_LEAK) ./$(NAME) $(ARG)"

clean:
	@echo "*** $(YEL)Removing$(D) deps $(YEL)object files$(D)"
	@if [ -d "$(BUILD_PATH)" ] || [ -d "$(TEMP_PATH)" ]; then \
		if [ -d "$(BUILD_PATH)" ]; then \
			$(RM) $(BUILD_PATH); \
			echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(TEMP_PATH)" ]; then \
			$(RM) $(TEMP_PATH); \
			echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to clean!$(D)]"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo "* $(YEL)Removing $(CYA)$(NAME)$(D) file: $(_SUCCESS)"; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to be fcleaned!$(D)]"; \
	fi

re: fclean all


.PHONY: all clean fclean re valgrind

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
