comp	:=	c++ -Wall -Werror -Wextra -pedantic -MMD -MP -std=c++98
comp	:=	c++ -Wall -Werror -Wextra -std=c++98
rmv	:=	rm -rf

path	:=	"assets/"

name	:=	btc
src	:=	main.cpp BitcoinExchange.cpp

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
		@ printf "\t\"make sure you have downloaded input._txt && data._tar \n\n"
		@ echo "you can do [curl -O ] "
		@ echo "you can do [wget ] "
		@ echo "you can do [tar -xvzf ] "
		@ echo ""
		@ echo "[en] come on baby break my code"
		@ echo "[fr] viens, brise mon code"
		@ echo ""

run	:	re
		@ echo ""
		@ echo "::: EVAL input :::"
		@ echo ""
		@ ./$(name) $(path)input.csv
		@ echo ""
		@ echo "::: Subject input :::"
		@ echo ""
		@ ./$(name) $(path)input.txt
		@ echo ""
		@ make clean

r	:	re

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out out
t	:	test
test	:	run
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f

