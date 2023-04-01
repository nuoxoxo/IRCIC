comp	:=	cc -D P=printf -D M=main -D C=char -D F=if -D I=int -w
rmv	:=	rm -rf

name	:=	smallest
src	:=	smallest.c

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
		@ make clean

test	:	re
		./$(name) 1 2
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
