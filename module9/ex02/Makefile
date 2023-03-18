comp	:=	c++ -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98
comp	:=	c++ -Wall -Werror -Wextra -std=c++98
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
		@ echo "you can do [ make test ] "
		@ printf "you can do [ ./PmergeMe \`shuf -i 1-100000 -n 3000 | tr \"\\\\n\" \" \"\` ] "
		@ echo ""
		@ echo ""

run	:	re
		@ echo "(misc.)"
		@ ./$(name) 42 80 82 96 64 58 69 71 73 1000
		@ echo ""
		@ echo ""
		@ echo "(misc.)"
		@ ./$(name) 20 88 47 86 64 2 30 71 3 57 63 68 54 22 70 19 34 90 44 97 32 87 50 78 56 91 4242 52 18 89 8 49 51 4 24 16 15 65 5 9 66 26
		@ echo ""
		@ echo ""
		@ echo "(Subject #1)"
		@ ./$(name) 3 5 9 7 4
		@ echo ""
		@ echo ""
		@ echo "(Subject #2)"
		@ ./$(name) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
		@ echo ""
		@ echo ""
		@ echo "(Eval #1)"
		@ ./$(name) `shuf -i 1-1000 -n 3000 | tr "\n" " " `
		@ echo ""
		@ echo ""
		@ echo "(Eval #2)"
		@ ./$(name) `jot -r 3000 1 1000 | tr '\n' ' '`
		@ echo ""
		@ echo ""
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
