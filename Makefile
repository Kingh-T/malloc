

ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$HOSTTYPE.so

EXEC		=	test 

C_FILES		=	malloc.c\
                realloc.c\
                free.c\
				findFreeBlock.c\
				requestSpace.c\
				getBlockPtr.c\
				ft_memcpy.c\
				allocateSmall.c\
				splitBlock.c\

O_FILES		=	$(C_FILES:.c=.o)
				
GCC		    =	gcc

FLAGS       =   -Wall -Wextra -Werror

$(VERBOSE).SILENT:

all : $(NAME)

$(NAME) :
	$(GCC) $(FLAGS) -c $(C_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

clean :
	    rm -f $(O_FILES)

fclean : clean
	     rm -f $(NAME)

re : fclean all
