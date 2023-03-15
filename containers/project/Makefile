comp	:=	c++ -Wall -Werror -Wextra -std=c++98
comp	:=	c++ -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98
rmv	:=	rm -rf

name	:=	out
src	:=	main.cc
inc	:=	$(foreach dir, $(INCLUDES),-I$(dir))
inc	:=	-I./include/ -I./iter/ -I./tree/ -I./util/

bud	:=	$(src:%.cc=%.o)

%.o	:	%.cc
		@ echo "compiling [$^] "
		$(comp) $(inc) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ echo "you can do [make f] "
		@ echo "you can do [make run] "
		@ echo ""

run	:	re
		@ ./$(name)
		@ make clean

r	:	run

all	:	$(name)

clean	:
		$(rmv) $(bud)

fclean	:	clean
		$(rmv) $(name) a.out

test	:	run
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
