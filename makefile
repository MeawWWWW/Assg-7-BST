compile: main.c
	 gcc  main.c -o p

run: p
	 ./p

clean: p
	 rm p