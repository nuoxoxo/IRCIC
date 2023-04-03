comp	:=	gcc -Wall -Werror -Wextra 
rmv	:=	rm -rf

name	:=	frame
src	:=	frame.c

bud	:=	$(src:%.c=%.o)

%.o	:	%.c
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\n"
		@ printf "\t[en] come on baby break my code\n"
		@ printf "\t[fr] viens, brise mon code\n\n\n"
		@ echo ""

run	:	re
		@ ./$(name)
		@ make clean

test	:	re
		@ ./$(name) "Hello World in a frame"
		@ echo ""
		@ ./$(name) "Hello World in a"
		@ echo ""
		@ ./$(name) "Hello World in"
		@ echo ""
		@ ./$(name) "Hello    World"
		@ echo ""
		@ ./$(name) "Hello World"
		@ echo ""
		@ ./$(name) "Hello"
		@ echo ""
		@ ./$(name) ""
		@ make clean

t	:	test
r	:	run

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out out

test	:	run
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
