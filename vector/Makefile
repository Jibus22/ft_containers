NAME = vector.out

##### SRC & OBJ PATH #####
SRCPATH = ./test
OBJPATH = $(SRCPATH)/obj

##### LIB #####
LIBS =
LIBSD = -lbsd

##### INCLUDE #####
PATH_INCLUDE = .
PATH_INCLUDE2 = ../iterators
PATH_INCLUDE3 = ../test_resources
HEADERS = $(PATH_INCLUDE)/*.hpp
HEADERS += $(PATH_INCLUDE2)/*.hpp
HEADERS += $(PATH_INCLUDE3)/*.hpp
INC = $(addprefix -I , $(PATH_INCLUDE) $(PATH_INCLUDE2) $(PATH_INCLUDE3))


##### COMPILER #####
CXX = clang++
##### COMPILATION FLAG #####
CXXFLAGS = -Wall -Wextra -Werror

##### OSTYPE #####
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# mac
	CXXFLAGS += -D DARWIN
else
	#Linux and others...
	CXXFLAGS += -D LINUX
endif

##### SRCS #####
SRCS = $(addprefix $(SRCPATH)/, main.cpp iteratorsTest.cpp capacityTest.cpp\
	   elementAccessTest.cpp modifiersTest.cpp)

OBJ = $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)


### RULES ###

all : mk_objdir $(NAME)


mk_objdir:
	@if [ ! -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi


$(NAME) : message $(OBJ)
	@echo "\n$(END)$(BLUE)# Making $(NAME) #$(END)$(GREY)"
	$(CXX) -o $@ $(OBJ)
	@echo "\n$(END)$(GREEN)# $(NAME) is built #$(END)"

message :
	@echo "\n$(END)$(BLUE)# Making $(NAME) objects #$(END)$(GREY)"


$(OBJPATH)/%.o : $(SRCPATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

### CLEAN ###
.PHONY : sanitize clean fclean re

clean :
	@echo "$(END)$(RED)# removing $(NAME) objects #$(END)$(GREY)"
	rm -rf $(OBJ)

fclean : clean
	@echo "$(END)$(RED)\n# removing $(NAME) #$(END)$(GREY)"
	rm -f $(NAME)

re : fclean all

