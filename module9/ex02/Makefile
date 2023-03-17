comp	:=	c++ -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98
comp	:=	c++ -Wall -Wextra -std=c++98
rmv	:=	rm -rf

name	:=	btc
name	:=	RPN
name	:=	PmergeMe
src		:=	main.cpp PmergeMe.cpp

bud		:=	$(src:%.cpp=%.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\t"
		@ printf "\"are you using the right compiler? \"\n\n"
		@ echo "you can do [ make f ] "
		@ printf "you can do [ ./PmergeMe \`shuf -i 1-100000 -n 3000 | tr \"\\\\n\" \" \"\` ] "
		@ echo ""
		@ echo ""

run	:	re
		@ ./$(name) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
		@ make clean
		@ echo ""
		@ echo ""

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
