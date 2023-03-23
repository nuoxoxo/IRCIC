comp	:=	c++ -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98
comp	:=	c++ -Wall -Werror -Wextra -std=c++98
rmv	:=	rm -rf

name	:=	btc
name	:=	RPN
src	:=	main.cpp RPN.cpp

bud	:=	$(src:%.cpp=%.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\n"
		@ printf "\t[en] come on baby break my code\n"
		@ printf "\t[fr] viens, brise mon code\n\n\n"
		@ printf "you can do [ ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 + \" ] \n"
		@ printf "you can do [ ./RPN \"9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 - \" ] \n"
		@ printf "you can do [ ./RPN \"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / \" ] \n"
		@ echo ""
		@ echo "you can do [ make test ] ( 👈 some samplers to show how it works)"
		@ echo ""

run	:	re
		@ ./$(name)
		@ make clean

test	:	re
		@ ./$(name) test
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
