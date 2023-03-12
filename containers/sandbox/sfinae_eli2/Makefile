comp	:=	c++ -Wall -Werror -Wextra -std=c++98
rmv	:=	rm -rf
name	:=	out
src	:=	main.cc
bud	:=	$(src:%.cc=%.o)

%.o	:	%.cc
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@

run	:	re
		@#@ echo "./$(name) | c++filt -t \n"
		@ ./$(name)
		@ make clean

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

all	:	$(name)
r	:	run
f	:	fclean
re	:	f all

.PHONY	:	fclean clean all re f
