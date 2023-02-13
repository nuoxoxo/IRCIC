comp	:=	c++ -Wall -Werror -Wextra -std=c++98
name	:=	out
rmv	:=	rm -rf

src	:=	main.cpp

bud	:=	$(src:%.cpp=%.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

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
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

test	:	run
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
