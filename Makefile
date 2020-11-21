##
## EPITECH PROJECT, 2020
## NWP_myftp_2019
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(YELLO_C)

##### client

NAME_CLIENT	=	my_client

ROOT_PATH_CLIENT	=	./client/
SRC_NAME_CLIENT		=	src
INCL_NAME_CLIENT	=	include
INCL_PATH_CLIENT	=	$(ROOT_PATH_CLIENT)$(INCL_NAME_CLIENT)
SRC_PATH_CLIENT	=	$(ROOT_PATH_CLIENT)$(SRC_NAME_CLIENT)

SRC_CLIENT	=	main.c	\
				client.c

SRCS_CLIENT	=	$(SRC_CLIENT:%=$(SRC_PATH_CLIENT)/%)
OBJ_CLIENT	=	$(SRCS_CLIENT:.c=.o)

CFLAGS	=	-I $(INCL_PATH_CLIENT)


#### server

NAME_SERVER	=	myftp

ROOT_PATH_SERVER		=	./server/
SRC_NAME_SERVER			=	src
INCL_NAME_SERVER		=	include
INCL_PATH_SERVER		=	$(ROOT_PATH_SERVER)$(INCL_NAME_SERVER)
SRC_PATH_SERVER		=	$(ROOT_PATH_SERVER)$(SRC_NAME_SERVER)

SRC_SERVER		=	main.c	\
		myftp.c	\
		socket.c	\
		client.c	\
		manager.c

SRC_SERVER_COMMAND	=	commands/pass.c \
						commands/user.c \
						commands/quit.c \
						commands/rein.c \
						commands/pasv.c	\
						commands/noop.c \
						commands/pwd.c	\
						commands/syst.c \
						commands/cdup.c \
 						commands/cwd.c \
						commands/dele.c \
						commands/rmd.c \
						commands/mkd.c \
						commands/mode.c \
						commands/help.c \
						commands/abor.c \
						commands/allo.c \
						commands/type.c \
 						commands/stou.c \
						commands/nlist.c \
						commands/rest.c \
						commands/stat.c \
						commands/site.c \
 						commands/rnfr.c \
						commands/rnto.c \
						commands/smnt.c \
						commands/stru.c \
						commands/port.c \
						commands/list.c				
# 						commands/retr.c \
# 						commands/stor.c \
#						commands/appe.c \

SRCS_SERVER		=	$(SRC_SERVER:%=$(SRC_PATH_SERVER)/%) $(SRC_SERVER_COMMAND:%=$(SRC_PATH_SERVER)/%)
OBJ_SERVER		=	$(SRCS_SERVER:.c=.o)

CC	= gcc

all:	server client message 

CFLAGS	=	-I ./server/include -g
CFLAGS	+=	-I ./client/include -g

server:	$(OBJ_SERVER)
	
	@$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) && \
	$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME_SERVER)\n"$(DEFAULT) || \
	$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME_SERVER)\n"$(DEFAULT)



client:	$(OBJ_CLIENT)
	@$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) && \
	$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME_CLIENT)\n"$(DEFAULT) || \
	$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME_CLIENT)\n"$(DEFAULT)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" ____        _ _     _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| __ ) _   _(_) | __| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ \| | | | | |/ _\` |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_) | |_| | | | (_| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|____/ \__,_|_|_|\__,_|"$(DEFAULT)
	@$(LINE_RETURN)

clean:
	@$(RM) $(OBJ_SERVER)
	@$(RM) $(OBJ_CLIENT)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(OBJ_SERVER)'s object files"$(DEFAULT) \
		$(LIGHT_RED)"$(OBJ_CLIENT)'s object files"$(DEFAULT) \
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT);

fclean: clean
	@$(RM) $(NAME_CLIENT)
	@$(RM) $(NAME_SERVER)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME_CLIENT)"$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME_SERVER)"$(DEFAULT)

re:	fclean all

.PHONY: all server client clean fclean re
