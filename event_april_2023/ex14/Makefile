comp	:=	c++ -std=c++17
rmv	:=	rm -rf

name	:=	out
src	:=	main.c

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
