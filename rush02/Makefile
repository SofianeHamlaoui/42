main:
	cc -Werror -Wall -Wextra ex*/includes/*.h  ex*/src/*.c
sanitize:
	cc -Werror -Wall -Wextra -g3 -fsanitize=address ex*/includes/*.h  ex*/src/*.c
fclean:
	rm *.out && rm ex*/includes/*.gch  && rm -rf a.out.dSYM/
norme:
	norminette -R CheckForbiddenSourceHeader ex00/ && make main
