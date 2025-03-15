#******************************************************************************#
# Makefile                                       #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2022/10/24 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - APACHE 2  :: Update - 2024/06/08 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
#******************************************************************************#

# *************************** [v] MAIN SOURCES [v] *************************** #
MAIN_SRC	=	./GRAPHIC/\#EVENT_HOOKS/\#EVENT_HOOK_CLOSE.c \
				./GRAPHIC/\#EVENT_HOOKS/\#EVENT_HOOK_KEY_DOWN.c \
				./GRAPHIC/\#EVENT_HOOKS/\#EVENT_HOOK_KEY_UP.c \
				./GRAPHIC/\#EVENT_HOOKS/\#EVENT_HOOK_LOOP.c \
				./GRAPHIC/\#EVENT_HOOKS/\#EVENT_HOOK_MOUSE.c \
				./GRAPHIC/\#EVENT_HOOKS/\#EVENT_HOOK_RESIZE.c \
				./GRAPHIC/\#FUNCTIONS/\#GRAPHIC_INIT.c \
				./GRAPHIC/\#FUNCTIONS/\#GRAPHIC_SETUP.c \
				./GRAPHIC/\#FUNCTIONS/\#GRAPHIC_LOOP/\#GRAPHIC_LOOP.c \
				./GRAPHIC/\#FUNCTIONS/\#GRAPHIC_SLEEP/\#GRAPHIC_SLEEP.c \
				./GRAPHIC/\#FUNCTIONS/\#GRAPHIC_TIME/\#GRAPHIC_TIME.c \
				./GRAPHIC/\#FUNCTIONS/\#WINDOW_CLOSE/\#WINDOW_CLOSE.c \
				./GRAPHIC/\#FUNCTIONS/\#WINDOW_OPEN/\#WINDOW_OPEN.c \
				./GRAPHIC/\#FUNCTIONS/\#WINDOW_TITLE/\#WINDOW_TITLE.c
# *************************** [^] MAIN SOURCES [^] *************************** #

# **************************** [v] VARIABLES [v] ***************************** #
MACOS_OPENGL_SUPPORTED := \
	$(shell test -d "/System/Library/Frameworks/OpenGL.framework" && echo yes)
	# [COMPILER]
		CC			=	gcc
	# [COMPILER]
	# [PRODUCT]
		NAME		=	graphic.a
	# [PRODUCT]
	# [COMPILER FLAGS]
		CFLAGS		=	-O3 -Wall -Wextra -Werror
		CFLAGS		+= -Wno-unused-command-line-argument
		ifeq ($(shell uname -s),Darwin)
			CFLAGS += -framework Cocoa # CORE GRPAHICS
			CFLAGS += -framework AudioToolbox # AUDIO HANDLE
			ifeq ($(MACOS_OPENGL_SUPPORTED), yes)
				CFLAGS += -DGL_SILENCE_DEPRECATION # IGNORE OS WARNINGS
				# MACOS IS GIVING WARNINGS IF YOU HAVE OPENGL ABOVE MAC - 10.14
				CFLAGS += -D__APPLE_OPENGL__ # OPENGL
			endif
		else
			CFLAGS += -lX11 -lasound # X11
		endif
	# [COMPILER FLAGS]
	# [.c STRINGS TO .o]
		MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
	# [.c STRINGS TO .o]
	# ANIMATION VARIABLES
		TERMINAL_LEN	:=	\
			$(eval TERMINAL_LEN := $(shell tput cols))$(TERMINAL_LEN)
		NUMBER_OF_FILES	:=	0
		FILE_COUNTER	:=	0
		N_OBJ			:=	$(eval N_OBJ := $$(shell find "." \
		-name '*.o' -type f | wc -w | sed "s/ //g" | bc))$(N_OBJ)
	# ANIMATION VARIABLES
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	= \033[0m
	C_BLINK	= \033[5m
	F15		= \033[38;5;15m
	B1F11	= \033[48;5;1m\033[38;5;11m
	B12F15	= \033[48;5;12m\033[38;5;15m
	B1F15	= \033[48;5;1m\033[38;5;15m
	B2F15	= \033[48;5;2m\033[38;5;15m
	F11		= \033[38;5;11m
	F13		= \033[38;5;13m
	F14		= \033[38;5;14m
	F10		= \033[38;5;10m
# ****************************** [^] COLORS [^] ****************************** #

# ***************************** [v] FUNCIONS [v] ***************************** #
define progress_bar
	$(eval PBAR := $(shell echo $(1)*100/$(2)*100/100 | bc))
	$(eval PDONE := $(shell echo $(PBAR)*3/10 | bc))
	$(eval PLEFT := $(shell echo 30-$(PDONE) | bc))
	$(eval PSEQ := $(shell seq 0 1 $(PLEFT) 2>/dev/null))
	$(eval PEMPTY := $(shell if [ "$(1)" -ne "$(2)" ]; \
		then printf ".%.0s" $(PSEQ); fi))
	$(eval PFILL := $(shell printf "\#%.0s" $(shell seq 1 $(PDONE))))
	@printf "\r%*s\r $(F11)[$(F14)$(PFILL)$(PEMPTY)$(F11)] $(PBAR)%% - \
		$(F10)[$(1)/$(2)]$(F11) [$(F13)$(3)$(F11)$(C_RESET)]" \
		$(TERMINAL_LEN) " "
endef
# ***************************** [^] FUNCIONS [^] ***************************** #

%.o: %.c
	$(eval NUMBER_OF_FILES := $(shell echo $(MAIN_SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))
	$(eval FILE_COUNTER := $(shell echo $(FILE_COUNTER) + 1 | bc))
	$(call progress_bar,$(FILE_COUNTER),$(NUMBER_OF_FILES),$<)
	@rm -f $(NAME) 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null || (\
		echo "\n\n $(B1F15) Failed to compile [$(F11)$<$(F15)] $(C_RESET)\n" &&\
		$(CC) $(CFLAGS) -c $< -o $@)

all: $(NAME)

$(NAME): $(MAIN_OBJ)
	@ar -rcs $(NAME) $(MAIN_OBJ) && \
		echo "\n\n $(C_BLINK)$(B2F15) $(NAME) is ready! $(C_RESET)\n"

c: clean
clear: clean
clean:
	@rm $(MAIN_OBJ) $(BONUS_OBJ) 2>/dev/null && \
		echo "\n $(B1F15) Objects are cleared! $(C_RESET)\n" || \
		echo "\n $(B12F15) Nothing to clear! $(C_RESET)\n"
	$(eval N_OBJ := "0")

fc: fclean
fclean: clean
	@rm $(NAME) $(BONUS_EXE) 2>/dev/null && \
		echo "\n $(B1F11) $(NAME) $(F15)deleted! $(C_RESET)\n" || \
		echo "\n $(B12F15) $(NAME) is not exist already! $(C_RESET)\n"

re: fc all

.PHONY: all fclean fc clean clear c