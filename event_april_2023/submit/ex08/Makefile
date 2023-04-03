comp	:=	gcc -Wall -Werror -Wextra 
rmv	:=	rm -rf

name	:=	blackjack
src	:=	blackjack.c

bud	:=	$(src:%.c=%.o)

%.o	:	%.c
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ printf "\n\n"
		@ printf "\t[en] come on baby break my code\n"
		@ printf "\t[fr] viens, brise mon code\n\n"
		@ echo ""
		@ echo "[$@] is ready"

run	:	re
		@ ./$(name)
		@ make clean

test	:	re
		@ ./$(name) "D8"
		@ echo "expected: 18"
		@ echo ""
		@ ./$(name) "A4"
		@ echo "expected: 15"
		@ echo ""
		@ ./$(name) "AA8"
		@ echo "expected: 20"
		@ echo ""
		@ ./$(name) "339A6"
		@ echo "expected: 22"
		@ echo ""
		@ ./$(name) "AA8A"
		@ echo "expected: Blackjack!"
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
