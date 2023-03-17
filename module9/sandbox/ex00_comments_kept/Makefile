comp	:=	c++ -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98
comp	:=	c++ -Wall -Werror -Wextra -std=c++98
rmv	:=	rm -rf

name	:=	btc
src	:=	main.cpp

bud	:=	$(src:%.cpp=%.o)

%.o	:	%.cc
		 echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		 echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ echo "you can do [make f] "
		@ echo "you can do [make run] "
		@ echo ""

run	:	re
		@ ./$(name) input.txt
		@ make clean

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

